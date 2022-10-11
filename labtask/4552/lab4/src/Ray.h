#pragma once

#include "Vec3.h"

constexpr size_t DirX = 0U;
constexpr size_t DirY = 1U;
constexpr size_t DirZ = 2U;

class Ray
{
private:
	Point3 m_Origin;
	Vec3 m_Direction;

public:
	inline Ray(const Point3& origin, const Vec3& direction) : m_Origin{ origin }, m_Direction{ direction } {}
	inline Ray() : Ray{ {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0} } {}

	inline Point3 Origin() const { return m_Origin; }
	inline Vec3 Direction() const { return m_Direction; }

	inline Point3 At(double t) const
	{
		return m_Origin + t * m_Direction;
	}
};