#include "Box.h"

#include "blaze/Math.h"

using TMat2D = blaze::StaticMatrix<double, 3, 3>;

Box::Box(const std::array<Point, 4> vertices)
		: m_Vertices{vertices}, m_Translation{0.0, 0.0}, m_Rotation{0.0}, m_Scale{0.0, 0.0}, m_Color{255, 255, 255}
{
}

Box::Box(const std::array<Point, 4> vertices, const Translation2D &translation, const Rotation2D &rotation, const Scale2D &scale, const Color &color)
		: m_Vertices{vertices}, m_Translation{translation}, m_Rotation{rotation}, m_Scale{scale}, m_Color{color}
{
}

Translation2D &Box::BaseTranslation()
{
	return m_Translation;
}

const Translation2D &Box::BaseTranslation() const
{
	return m_Translation;
}

Rotation2D &Box::BaseRotation()
{
	return m_Rotation;
}
const Rotation2D &Box::BaseRotation() const
{
	return m_Rotation;
}

Scale2D &Box::BaseScale()
{
	return m_Scale;
}

const Scale2D &Box::BaseScale() const
{
	return m_Scale;
}

Color &Box::BaseColor()
{
	return m_Color;
}

const Color &Box::BaseColor() const
{
	return m_Color;
}

void Box::Draw(Image &image) const
{
	//----------------------------------------        TASK 1        ----------------------------------------
	/* ToDo: From the stored coordinates(Point type) of the 4 vertices in m_Vertices std::vector,
	 *		1. Find out the transfromed vertex positions by:
	 *			a. Creating Translation (T), Rotation (R) and Scale (S) Matrices from the stored m_Translation,
	 *			   m_Rotation and m_Scale values (they are either aliased blaze vectors or just primitive double
	 *			   types). Check "ITransformable.h" for the aliases. You can use the alias TMat2D to declare 2D
	 *			   homogenious transformation matrix type, the alias is defined at the beginning of this file.
	 *			b. Applying scaling, rotation and then translation to each of the vertex positions (a blaze vector)
	 *			   to get the new transformed vertex positions and store them somewhere. For each of the vertices,
	 *			   a blaze vector needs to be created first (there is a faster way using matrix, not necessary now)
	 *		2. Once the transformed coordinates are found and stored, draw lines between (1st, 2nd), (2nd, 3rd),
	 *		   (3rd, 4th), (4th, 1st), (1st, 3rd) and (2nd, 4th) vertices to get a box line drawing with a 'X' shape
	 *		   connecting the diagonals. A line can be draw by making a call to:
	 *
	 *				DrawLine(image, VertexA, VertexB, m_Color); // Just update the values of Vertex A and B
	 */

	//---------------------------------------- INSERT YOUR CODE HERE ----------------------------------------

	using Vertex = blaze::StaticVector<double, 3>;

	TMat2D translationMatrix = {
			{1, 0, BaseTranslation()[0]},
			{0, 1, BaseTranslation()[1]},
			{0, 0, 1}};
	TMat2D rotationMatrix = {
			{cos(BaseRotation()), -sin(BaseRotation()), 0},
			{sin(BaseRotation()), cos(BaseRotation()), 0},
			{0, 0, 1}};
	TMat2D scaleMatrix = {
			{BaseScale()[0], 0, 0},
			{0, BaseScale()[1], 0},
			{0, 0, 1}};
	TMat2D Result = translationMatrix * rotationMatrix * scaleMatrix;

	auto pointToVertex = [](Point vv)
	{
		return Vertex{vv.X, vv.Y, 1};
	};

	Vertex otopL = pointToVertex(m_Vertices[0]);
	Vertex otopR = pointToVertex(m_Vertices[1]);
	Vertex obottomR = pointToVertex(m_Vertices[2]);
	Vertex obottomL = pointToVertex(m_Vertices[3]);

	// Vertex otopL = Vertex{m_Vertices[0].X, m_Vertices[0].Y, 1};
	// Vertex otopR = Vertex{m_Vertices[1].X, m_Vertices[1].Y, 1};
	// Vertex obottomR = Vertex{m_Vertices[2].X, m_Vertices[2].Y, 1};
	// Vertex obottomL = Vertex{m_Vertices[3].X, m_Vertices[3].Y, 1};

	Vertex topL = Result * otopL;
	Vertex topR = Result * otopR;
	Vertex bottomR = Result * obottomR;
	Vertex bottomL = Result * obottomL;

	DrawLine(image, Point(topL[0], topL[1]), Point(topR[0], topR[1]), m_Color);
	DrawLine(image, Point(bottomL[0], bottomL[1]), Point(topR[0], topR[1]), m_Color);
	DrawLine(image, Point(topL[0], topL[1]), Point(bottomR[0], bottomR[1]), m_Color);
	DrawLine(image, Point(bottomL[0], bottomL[1]), Point(bottomR[0], bottomR[1]), m_Color);
	DrawLine(image, Point(topL[0], topL[1]), Point(bottomL[0], bottomL[1]), m_Color);
	DrawLine(image, Point(bottomR[0], bottomR[1]), Point(topR[0], topR[1]), m_Color);
}
