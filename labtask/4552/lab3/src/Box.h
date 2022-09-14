#pragma once

#include "IActor.h"
#include "Curves.h"

class Box : public IActor
{
	std::array<Point, 4> m_Vertices; // Order: TopLeft, TopRight, BottomRight, BottomLeft
	Translation2D m_Translation;
	Rotation2D m_Rotation;
	Scale2D m_Scale;
	Color m_Color;

public:
	Box(const std::array<Point, 4> vertices);
	Box(const std::array<Point, 4> vertices,
		const Translation2D& translation, const Rotation2D& rotation, const Scale2D& scale, const Color& color);

	virtual Translation2D& BaseTranslation() override;
	virtual const Translation2D& BaseTranslation() const override;
	virtual Rotation2D& BaseRotation() override;
	virtual const Rotation2D& BaseRotation() const override;
	virtual Scale2D& BaseScale() override;
	virtual const Scale2D& BaseScale() const override;
	virtual Color& BaseColor() override;
	virtual const Color& BaseColor() const override;

	virtual void Draw(Image& image) const override;
};