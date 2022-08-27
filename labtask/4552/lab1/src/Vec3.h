#pragma once

#include <iostream>

class Vec3
{
private:
    double m_Values[3];

public:
    Vec3(double x, double y, double z);
    Vec3(double v);
    Vec3();

    double& x();
    double& y();
    double& z();
    double x() const ;
    double y() const ;
    double z() const ;

    bool operator==(const Vec3& other) const;
    bool operator!=(const Vec3& other) const;

    Vec3 operator-() const;
    double operator[](size_t index) const;
    double& operator[](size_t index);

    Vec3& operator+=(const Vec3& other);

    Vec3& operator*=(const double t);

    Vec3& operator/=(const double t);

    Vec3 operator+(const Vec3& other) const;

    Vec3 operator+(double t) const;

    Vec3 operator-(const Vec3& other) const;

    Vec3 operator-(double t) const;

    Vec3 operator*(const Vec3& other) const;

    Vec3 operator*(double t) const;

    Vec3 operator/(const Vec3& other) const;

    Vec3 operator/(double t) const;
    
    double LengthSquared() const;

    double Length() const;

    static double Dot(const Vec3& v1, const Vec3& v2);

    double Dot(const Vec3& other) const;

    static Vec3 Cross(const Vec3& v1, const Vec3& v2);

    Vec3 Cross(const Vec3& other) const;

    // Return true if the vector is close to zero in all dimensions
    bool NearZero() const;

    // Returns a vector with random x, y and z between [0.0, 1.0) for each
    static Vec3 Random();

    // Returns a vector with random x, y and z between [min, max) for each
    static Vec3 Random(double min, double max);
};

// Type Aliases for Vec3

using Point3 = Vec3;
using Color = Vec3;

// Utility Functions and extension of operators for doubles 

inline std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

Vec3 operator+(double t, const Vec3& v);

Vec3 operator-(double t, const Vec3& v);

Vec3 operator*(double t, const Vec3& v);

Vec3 operator/(double t, const Vec3& v);

// Returns a unit vector in the direction of v
Vec3 UnitVector(const Vec3& v);

inline Vec3 RandomInUnitSphere()
{
    // TODO: To be filled up in later labs
    return Vec3();
}

inline Vec3 RandomUnitVector()
{
    // TODO: To be filled up in later labs
    return Vec3();
}

inline Vec3 RandomInUnitDisk()
{
    // TODO: To be filled up in later labs
    return Vec3();
}

inline Vec3 Reflect(const Vec3& vec, const Vec3& normal)
{
    // TODO: To be filled up in later labs
    return Vec3();
}

// Calculates the angle between vec1 and vec2
double Angle(const Vec3& vec1, const Vec3& vec2);

inline Vec3 Refract(const Vec3& uv, const Vec3& n, double etaIOverEtaT)
{
    // TODO: To be filled up in later labs
    return Vec3();
}