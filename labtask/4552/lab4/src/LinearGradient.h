#pragma once

#include "Vec3.h"
#include "Util.h"

class LinearGradient
{
private:
	Color3 m_TopColor;
	Color3 m_BottomColor;

public:
	inline LinearGradient(const Color3& topColor, const Color3& bottomColor)
		: m_TopColor{ topColor }, m_BottomColor{ bottomColor } {}
	inline LinearGradient(const Color3& staticColor)
		: LinearGradient(staticColor, staticColor) {}
	inline LinearGradient()
		: LinearGradient(Color3{ 0.0, 0.0, 0.0 }, Color3{ 1.0, 1.0, 1.0 }) {}

	inline Color3 At(double t) const
	{
		return Lerp(m_BottomColor, m_TopColor, Clamp(t, 0.0, 1.0));
	}
};