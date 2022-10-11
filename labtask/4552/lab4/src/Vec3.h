#pragma once

#include "blaze/Math.h"

using Vec3 = blaze::StaticVector<double, 3>;
using Point3 = blaze::StaticVector<double, 3>;
using Color3 = blaze::StaticVector<double, 3>;

inline Vec3 UnitVector(const Vec3& vec)
{
	return vec / blaze::length(vec);
}

inline Vec3 Reflect(const Vec3& vec, const Vec3& normal)
{
	return vec - 2 * ( blaze::dot(vec, normal) * normal );
}