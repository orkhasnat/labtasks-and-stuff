#include "Vec3.h"

#include <cmath>

#include "Util.h"

Vec3::Vec3(double x, double y, double z) : m_Values{x, y, z} {}

Vec3::Vec3(double v) : Vec3{v, v, v} {}

Vec3::Vec3() : Vec3{0.0, 0.0, 0.0} {}

double &Vec3::x() { return m_Values[0]; }
double &Vec3::y() { return m_Values[1]; }
double &Vec3::z() { return m_Values[2]; }

double Vec3::x() const { return m_Values[0]; }
double Vec3::y() const { return m_Values[1]; }
double Vec3::z() const { return m_Values[2]; }

bool Vec3::operator==(const Vec3 &other) const
{
    // ToDo: Implement Equality
    return DoubleEq(m_Values[0], other.x()) && DoubleEq(m_Values[1], other.y()) && DoubleEq(m_Values[2], other.z());
}

bool Vec3::operator!=(const Vec3 &other) const
{
    // ToDo: Implement Inequality (Hint: Keep it bound to Equality)
    return !operator==(other);
}

Vec3 Vec3::operator-() const
{
    // ToDo: Implement Unary Negation
    return Vec3{-m_Values[0], -m_Values[1], -m_Values[2]};
}
double Vec3::operator[](size_t index) const
{
    // ToDo: Implement index access operator to GET X, Y and Z via index 0, 1 and 2 respectively as RVALUE
    return m_Values[index];
}
double &Vec3::operator[](size_t index)
{
    // ToDo: Implement index access operator to ACCESS X, Y and Z via index 0, 1 and 2 respectively as LVALUE REFERENCE
    return this->m_Values[index];
}

Vec3 &Vec3::operator+=(const Vec3 &other)
{
    // ToDo: Implement += operator to add element wise other vector to this vector and store it in this vector
    // Return reference to this vector
    m_Values[0] += other.x();
    m_Values[1] += other.y();
    m_Values[2] += other.z();
    return *this;
}

Vec3 &Vec3::operator*=(const double t)
{
    // ToDo: Implement *= operator to multiply the double t with each element of this vector and store it in this vector
    // Return reference to this vector
    m_Values[0] *= t;
    m_Values[1] *= t;
    m_Values[2] *= t;
    return *this;
}

Vec3 &Vec3::operator/=(const double t)
{
    // ToDo: Implement /= operator to divide each element of this vector by double t and store it in this vector
    // Return reference to this vector
    m_Values[0] /= t;
    m_Values[1] /= t;
    m_Values[2] /= t;
    return *this;
}

Vec3 Vec3::operator+(const Vec3 &other) const
{
    // ToDo: Element wise add the other vector to this vector and return a new vector containing the value

    return Vec3{m_Values[0] + other.x(), m_Values[1] + other.y(), m_Values[2] + other.z()};
}

Vec3 Vec3::operator+(double t) const
{
    // ToDo: Add double t with each of the elements of this vector and return a new vector containing the value
    return Vec3{m_Values[0] + t, m_Values[1] + t, m_Values[2] + t};
}

Vec3 Vec3::operator-(const Vec3 &other) const
{
    // ToDo: Element wise subtract the other vector from this vector and return a new vector containing the value
    return Vec3{m_Values[0] - other.x(), m_Values[1] - other.y(), m_Values[2] - other.z()};
}

Vec3 Vec3::operator-(double t) const
{
    // ToDo: Subtract double t with each of the elements of this vector and return a new vector containing the value
    return Vec3{m_Values[0] - t, m_Values[1] - t, m_Values[2] - t};
}

Vec3 Vec3::operator*(const Vec3 &other) const
{
    // ToDo: Element wise multiply the other vector from this vector and return a new vector containing the value
    return Vec3{m_Values[0] * other.x(), m_Values[1] * other.y(), m_Values[2] * other.z()};
}

Vec3 Vec3::operator*(double t) const
{
    // ToDo: Multiply double t with each of the elements of this vector and return a new vector containing the value
    return Vec3{m_Values[0] * t, m_Values[1] * t, m_Values[2] * t};
}

Vec3 Vec3::operator/(const Vec3 &other) const
{
    // ToDo: Element wise divide this vector by the other vector and return a new vector containing the value
    return Vec3{m_Values[0] / other.x(), m_Values[1] / other.y(), m_Values[2] / other.z()};
}

Vec3 Vec3::operator/(double t) const
{
    // ToDo: Elementwise divide this vector by the double t and return a new vector containing the value
    return Vec3{m_Values[0] / t, m_Values[1] / t, m_Values[2] / t};
}

double Vec3::LengthSquared() const
{
    // ToDo: Return the square of the length of this vector
    double _x = m_Values[0];
    double _y = m_Values[1];
    double _z = m_Values[2];
    return _x * _x + _y * _y + _z * _z;
}

double Vec3::Length() const
{
    // ToDo: Return the length of this vector (Hint: Keep it bound ot LegthSquared() function)
    return std::sqrt(LengthSquared());
}

double Vec3::Dot(const Vec3 &v1, const Vec3 &v2)
{
    // ToDo: Return the DOT product between v1 and v2
    return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

double Vec3::Dot(const Vec3 &other) const
{
    // ToDo: Return the DOT product between this and other vectors (Hint: Keep it bound to static Dot between v1 and v2)
    return Dot(*this, other);
}

Vec3 Vec3::Cross(const Vec3 &v1, const Vec3 &v2)
{
    // ToDo: Return the CROSS product between v1 and v2 as a new Vec3
    double ax = v1.x();
    double ay = v1.y();
    double az = v1.z();
    double bx = v2.x();
    double by = v2.y();
    double bz = v2.z();
    return Vec3{ay * bz - az * by, az * bx - ax * bz, ax * by - ay * bx};
}

Vec3 Vec3::Cross(const Vec3 &other) const
{
    // ToDo: Return the CROSS product between this and other vectors (Hint: Keep it bound to static Cross between v1 and v2)
    return Cross(*this, other);
}

bool Vec3::NearZero() const
{
    // ToDo: Return whether all 3 members of this vector is near zero (Abs is lower than K_EPSILON from Util.h)
    // It is necessary later on since floating point calculations are not accurate
    return !(m_Values[0] + m_Values[1] + m_Values[2] > 3 * K_EPSILON);
}

Vec3 Vec3::Random()
{
    // ToDo: Return a Vec3 having random X, Y and Z values between [0.0, 1.0) (Hint: Check Util.h)
    return RandomDouble() ; // Implicit conversion to Vec3{1000.0}
}

Vec3 Vec3::Random(double min, double max)
{
    // ToDo: Return a Vec3 having random X, Y and Z values between [min, max) (Hint: Check Util.h)
    return RandomDouble(min,max); // Implicit conversion to Vec3{1000.0}
}

Vec3 operator+(double t, const Vec3 &v)
{
    // ToDo: Overload + operator so that double + Vec3 can be performed (Hint: Just return Vec3 + double to flip ordering)
    return v+t;
}

Vec3 operator-(double t, const Vec3 &v)
{
    // ToDo: Overload - operator so that double - Vec3 can be performed (Hint: Like the previous one)
    return v-t;
}

Vec3 operator*(double t, const Vec3 &v)
{
    // ToDo: Overload * operator so that double * Vec3 can be performed (Hint: Like the previous one)
    return v*t;
}

Vec3 operator/(double t, const Vec3 &v)
{
    // ToDo: Overload / operator so that double / Vec3 can be performed (Hint: Like the previous one)
    return v/t;
}

Vec3 UnitVector(const Vec3 &v)
{
    // ToDo: Return a unit vector in the direction of v
    return Vec3{v.x() / v.Length(), v.y() / v.Length(), v.z() / v.Length()};
}

double Angle(const Vec3 &vec1, const Vec3 &vec2)
{
    // ToDo: Return the angle between vec1 and vec2 in radians

    return std::acos(vec1.Dot(vec2) / (vec1.Length() * vec2.Length()));
}