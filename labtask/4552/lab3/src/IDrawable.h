#pragma once

#include "Image.h"


class IDrawable
{
public:
	virtual void Draw(Image& image) const = 0;
};