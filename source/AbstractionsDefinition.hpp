#ifndef ABSTRACTIONSDEFINITION_HPP
#define ABSTRACTIONSDEFINITION_HPP

#include <math.h>
#define M_PI           3.14159265358979323846

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


class iMovable //something capable to move in a straight line
{
public:
  iMovable(const cVector &pos, const cVector& vel) : position(pos), velocity(vel) {}

  // access
  const cVector &Position() const { return position; }
  const cVector &Velocity() const { return velocity; }

  // change
  void Position(const cVector& pos) { position = pos; }
  void Velocity(const cVector &vel) { velocity = vel; }

protected:
  cVector position, velocity;
};

class cMove //motion in a straight line
{
public:
  void move(iMovable &m ) const
  {
    // new position as old position + velocity.
    m.Position(m.Position() + m.Velocity() );
  }
};


class iRotatable //something capable to rotate around a axis
{
public:
  iRotatable(double direction_, double angularVelocity_) 
    : direction(direction_), angularVelocity(angularVelocity_) {}

  // access
  double AngularVelocity() const { return angularVelocity; }
  double Direction() const { return direction; }
  const cVector& Position() const { return position; }
  double Velocity() const { return velocity; }

  cVector V() const 
  { 
      return cVector(velocity * cos(DirectionRad()), velocity * sin(DirectionRad()));
  }

  double DirectionRad() const {return 2 * M_PI * direction / 360;  }

  // change
  void AngularVelocity(double val) { angularVelocity = val; }
  void Direction(double val) { direction = val; }
  void Position(const cVector& pos) { position = pos; }
  void Velocity(double vel) { velocity = vel; }

  

protected:
  cVector position;
  double velocity, direction, angularVelocity; // degrees 
};

class cRotate //motion in a straight line
{
public:
  void Rotate(iRotatable& a) const
  {
    // new position as old position + velocity.
    a.Direction(a.Direction() + a.AngularVelocity());
    a.Position(a.Position() + a.V());


  }
};

class cAbstractionsDefinition
{
public:

protected:
};

#endif //#ifndef ABSTRACTIONSDEFINITION_HPP
  