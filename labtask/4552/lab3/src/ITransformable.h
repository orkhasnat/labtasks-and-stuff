#pragma once

//#include <array>

#include "blaze/Math.h"

using Translation2D = blaze::StaticVector<double, 2>;
using Rotation2D = double;
using Scale2D = blaze::StaticVector<double, 2>;

class ITransformable
{
public:
	virtual Translation2D& BaseTranslation() = 0;
	virtual const Translation2D& BaseTranslation() const = 0;
	virtual Rotation2D& BaseRotation() = 0;
	virtual const Rotation2D& BaseRotation() const = 0;
	virtual Scale2D& BaseScale() = 0;
	virtual const Scale2D& BaseScale() const = 0;
	virtual Color& BaseColor() = 0;
	virtual const Color& BaseColor() const = 0;
};