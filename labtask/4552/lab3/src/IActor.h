#pragma once

#include "IDrawable.h"
#include "ITransformable.h"

class IActor : public ITransformable, public IDrawable
{

};