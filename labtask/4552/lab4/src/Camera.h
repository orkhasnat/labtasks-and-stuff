#pragma once

#include "Vec3.h"
#include "Ray.h"

class Camera
{
private:
	Point3 m_Origin;
	Point3 m_LowerLeftCorner;
	Vec3 m_Horizontal;
	Vec3 m_Vertical;

public:
	inline Camera()
	{
		constexpr auto aspectRatio = 16.0 / 9.0;
		double viewportHeight = 2.0;
		double viewportWidth = viewportHeight * aspectRatio;
		double focalLength = 1.0;

		m_Origin = Point3{ 0.0, 0.0, 0.0 };
		m_Horizontal = Vec3{ viewportWidth, 0.0, 0.0 };
		m_Vertical = Vec3{ 0.0, viewportHeight, 0.0 };
		m_LowerLeftCorner = m_Origin - m_Horizontal / 2.0 - m_Vertical / 2.0 - Vec3{ 0.0, 0.0, focalLength };
	}

	inline const Point3& GetOrigin() const { return m_Origin; }

	inline Ray GetRay(double u, double v) const
	{
		return Ray{ m_Origin, m_LowerLeftCorner + u * m_Horizontal + v * m_Vertical - m_Origin };
	}
};