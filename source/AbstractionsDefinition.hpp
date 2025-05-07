#ifndef ABSTRACTIONSDEFINITION_HPP
#define ABSTRACTIONSDEFINITION_HPP

class cVector
{
public:
  using T = int;
  using data_type = int;

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

class cAbstractionsDefinition
{
public:

protected:
};

#endif //#ifndef ABSTRACTIONSDEFINITION_HPP
  