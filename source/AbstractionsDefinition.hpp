#ifndef ABSTRACTIONSDEFINITION_HPP
#define ABSTRACTIONSDEFINITION_HPP

#include <exception>
#include <math.h>

static constexpr double M_PI = 3.14159265358979323846;

class cVector
{
public:
  using T = double;
  using data_type = double;

  cVector() = default;
  cVector(const cVector& other) = default;
  cVector(T x_, T y_) : x(x_), y(y_) {}

  template< typename S >
  cVector(const S& other) : x(data_type(other.x)),
    y(data_type(other.y))
  {
  }

  cVector& operator=(const cVector& rhs) = default;
  cVector& operator+=(const cVector& rhs)
  {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  cVector& operator-=(const cVector& rhs)
  {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  cVector& reverse() { x = -x; y = -y; return *this; };
  const cVector operator-() const { return cVector(-x, -y); }
  const cVector operator+(const cVector& other) const { return cVector(x + other.x, y + other.y); }
  const cVector operator-(const cVector& other) const { return cVector(x - other.x, y - other.y); }

  bool operator==(const cVector& rhs) const { return (x == rhs.x) && (y == rhs.y); }
  bool operator!=(const cVector& rhs) const { return (x != rhs.x) || (y != rhs.y); }

public:
  T x, y;
};

// base class of exception used in task. It has name.
class cException : public std::exception
{
public:
    cException(const char* sz) : szWhat(sz) {}

    const char* what() const noexcept { return szWhat; }

protected:
    const char* szWhat;
};


class iMovable //something capable to move in a straight line
{
public:
    virtual ~iMovable() {}

    // access
    virtual const cVector& Position() const = 0;
    virtual const cVector& Velocity() const = 0;

    // change
    virtual void Position(const cVector& pos) = 0;
    virtual void Velocity(const cVector& vel) = 0;
};

class cMovable : public iMovable
{
public:
  cMovable(const cVector &pos, const cVector& vel) : position(pos), velocity(vel) {}

  // access
  const cVector &Position() const override { return position; }
  const cVector &Velocity() const override { return velocity; }

  // change
  void Position(const cVector& pos) override { position = pos; }
  void Velocity(const cVector &vel) override { velocity = vel; }

protected:
  cVector position, velocity;
};

class cMove  // class performing moving along stright line
{
private:
    cMove(const cMove&) = delete;
    cMove& operator=(const cMove&) = delete;

public:
    cMove(iMovable& m_) : m(m_) {}

public:
    void Execute()
    {
        // new position as old position + velocity.
        m.Position(m.Position() + m.Velocity());
    }

public:
    iMovable& m;
};


class iRotatable //interface class of something capable to rotate around a axis
{
public:
  virtual ~iRotatable() {}

  // access
  virtual double AngularVelocity() const = 0;
  virtual double Direction() const = 0;

  // change
  virtual void AngularVelocity(double val) = 0;
  virtual void Direction(double val) = 0;
};

class cRotatable : public iRotatable
{
public:
    cRotatable(double dir, double vel) : direction(dir), angularVelocity(vel) {}
    // access
    double AngularVelocity() const override { return angularVelocity; }
    double Direction() const override { return direction; }

    // change
    void AngularVelocity(double val) override { angularVelocity = val; }
    void Direction(double val) override { direction = val; }

protected:
    double direction, angularVelocity; // degrees 
};


class cRotate //class to perform rotation
{
private:
    cRotate(const cRotate&) = delete;
    cRotate& operator=(const cRotate&) = delete;

public:
    cRotate(iRotatable& m_) : m(m_) {}

public:
    void Execute()
    {
        m.Direction(m.Direction() + m.AngularVelocity());
    }

public:
    iRotatable& m;
};

#endif //#ifndef ABSTRACTIONSDEFINITION_HPP
  