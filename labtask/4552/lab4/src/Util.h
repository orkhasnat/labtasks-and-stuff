#pragma once

#include <cmath>
#include <memory>
#include <limits>
#include <random>

#define RANDOM_NONDET 1

// Constants

constexpr double K_EPSILON = std::numeric_limits<double>::epsilon();
constexpr double INF = std::numeric_limits<double>::infinity();
constexpr double PI = 3.1415926535897932385;

// Utility Functions

// Converts degrees to radian
constexpr double DegreesToRadians(double deg)
{
	return deg * PI / 180.0;
}

// Returns random double in range [0.0, 1.0).
inline double RandomDouble()
{
#if RANDOM_NONDET
	static std::random_device rd;
	static std::mt19937 generator(rd());
#else
	static std::mt19937 generator;
#endif
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	return distribution(generator);
}


// Returns random double in range [min, max).
inline double RandomDouble(double min, double max)
{
	return min + (max - min) * RandomDouble();
}

// Clamps the value x between [min, max].
template<typename T>
constexpr double Clamp(T x, T min, T max)
{
	return x < min ? min :
		x > max ? max :
		x;
}

// Linearly interpolates between item1 and item2 based on ratio
template<typename T>
inline T Lerp(const T& item1, const T& item2, double ratio)
{
	return item1 * (1.0 - ratio) + item2 * ratio;
}

// Double Equality
constexpr bool DoubleEq(double d1, double d2)
{
	if (d2 > d1)
	{
		return (d2 - d1) <= 1e-12;
	}
	else return (d1 - d2) <= 1e-12;
}