#pragma once

#include "Vec3.h"

class Light
{
private:
	Point3 m_Position;
	Color3 m_Color;
	double m_Intensity;
	double m_Exposure;

public:
	inline Light(const Point3& position, const Color3& color, double intensity, double exposure)
		: m_Position{ position }, m_Color{ color }, m_Intensity{ intensity >= 0.0 ? intensity : 0.0 }, m_Exposure{ exposure } {}
	inline Light() : Light(Point3{ 0.0, 10.0, 0.0 }, Color3{ 1.0, 1.0, 1.0 }, 1.0, 0.0) {}

	inline const Point3& GetPosition() const { return m_Position; }
	inline void SetPosition(const Point3& position) { m_Position = position; };
	
	inline const Color3& GetColor() const { return m_Color; }
	inline void SetColor(const Color3& color) { m_Color = color; }

	inline double GetIntensity() const { return m_Intensity; }
	inline void SetIntensity(double intensity) { m_Intensity = (intensity >= 0.0) ? intensity : 0.0; }

	inline double GetExposure() const { return m_Exposure; }
	inline void SetExposure(double exposure) { m_Exposure = exposure; }

	inline Color3 GetIllumination() const { return m_Color * m_Intensity * blaze::pow(2.0, m_Exposure); }
};