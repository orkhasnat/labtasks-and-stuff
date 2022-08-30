#include "Curves.h"
#include "blaze/Blaze.h"
/**************************** Required Basis/Spline Matrices ****************************
 *																						*
 *											| 1.0  -3.0   3.0  -1.0 |					*
 *			Bezier Spline Matrix =>			| 0.0   3.0  -6.0   3.0 |					*
 *											| 0.0   0.0   3.0  -3.0 |					*
 *											| 0.0   0.0   0.0   1.0 |					*
 *																						*
 *											| 1.0  -3.0   3.0  -1.0 |					*
 *			BSpline Spline Matrix =>   (1/6)| 4.0   0.0  -6.0   3.0 |					*
 *											| 1.0   3.0   3.0  -3.0 |					*
 *											| 0.0   0.0   0.0   1.0 |					*
 *																						*
 ****************************************************************************************/

// ToDo: Declare a function to get Monomial Basis Vector [1, t, t^2, t^3] based on the value of 't'
blaze::StaticVector<double, 4> GetMonomialBasis(double t)
{
	return blaze::StaticVector<double, 4>{1, t, t * t, t * t * t};
}
// ---------------- Insert Code Here ----------------

// ToDo: [Optional] Declare global constant Matrices for Spline/Basis Vectors
blaze::StaticMatrix<double, 4, 4> BezierSplineMatrix = {
		{1.0, -3.0, 3.0, -1.0},
		{0.0, 3.0, -6.0, 3.0},
		{0.0, 0.0, 3.0, -3.0},
		{0.0, 0.0, 0.0, 1.0}};
blaze::StaticMatrix<double, 4, 4> __BsplineSplineMatrix = {
		{1.0, -3.0, 3.0, -1.0},
		{4.0, 0.0, -6.0, 3.0},
		{1.0, 3.0, 3.0, -3.0},
		{0.0, 0.0, 0.0, 1.0}};
// blaze::StaticMatrix<double, 4, 4> BsplineSplineMatrix = {
// 		{1.0/6.0, -3.0/6.0, 3.0/6.0, -1.0/6.0},
// 		{4.0/6.0, 0.0/6.0, -6.0/6.0, 3.0/6.0},
// 		{1.0/6.0, 3.0/6.0, 3.0/6.0, -3.0/6.0},
// 		{0.0/6.0, 0.0/6.0, 0.0/6.0, 1.0/6.0}};

blaze::StaticMatrix<double, 4, 4> BsplineSplineMatrix = (1.0 / 6.0) * __BsplineSplineMatrix;

inline double Distance(int x1, int y1, int x2, int y2)
{
	int x = x1 - x2;
	int y = y1 - y2;
	return std::sqrt(x * x + y * y);
}

Image &DrawCircle(Image &image, const Point &point, int radius, const Color &color)
{
	// ToDo: Draw a circle of the parameter 'radius' centered at parameter 'point'
	// Algorithm: If radius is 'r', then you can think of a square in which
	// The circle is fitted. If the center is c, then one corner of the square is
	// (c.X - r, c.Y - r) and another one is (c.X + r, c.Y + r). Write a nested loop
	// (2 loops, one inside another) to check each of the points and if the Euclidean
	// Distance between a point and the center is less than or equal to 'r', color that
	// pixel in parameter 'color'. A reference to the original image is returned.

	// ---------------- Insert Code Here ----------------
	int cx = point.X;
	int cy = point.Y;
	for (int j = cy - radius; j <= cy + radius; j++)
		for (int i = cx - radius; i <= cx + radius; i++)
			if (Distance(cx, cy, i, j) <= radius)
				image.Pixel(j, i) = color;
	return image;
}

Image &DrawLineLow(Image &image, const Point &p0, const Point &p1, const Color &color)
{
	int dx = p1.X - p0.X;
	int dy = p1.Y - p0.Y;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = (2 * dy) - dx;
	int y = p0.Y;

	for (int x = p0.X; x <= p1.X; x++)
	{
		image.Pixel(y, x) = color;
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else
		{
			D = D + 2 * dy;
		}
	}
	return image;
}

Image &DrawLineHigh(Image &image, const Point &p0, const Point &p1, const Color &color)
{
	int dx = p1.X - p0.X;
	int dy = p1.Y - p0.Y;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = (2 * dx) - dy;
	int x = p0.X;

	for (int y = p0.Y; y <= p1.Y; y++)
	{
		image.Pixel(y, x) = color;
		if (D > 0)
		{
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else
		{
			D = D + 2 * dx;
		}
	}
	return image;
}

Image &DrawLine(Image &image, const Point &p0, const Point &p1, const Color &color)
{
	if (abs(p1.Y - p0.Y) < abs(p1.X - p0.X))
	{
		if (p0.X > p1.X)
		{
			return DrawLineLow(image, p1, p0, color);
		}
		else
			return DrawLineLow(image, p0, p1, color);
	}
	else
	{
		if (p0.Y > p1.Y)
		{
			return DrawLineHigh(image, p1, p0, color);
		}
		else
			return DrawLineHigh(image, p0, p1, color);
	}
	return image;
}

Image &DrawBezierCurve(Image &image, const std::vector<Point> &points, const Color &color, double samplingInterval)
{
	// ToDo: Draw a Cubic Bezier curve between the points. There will always be exactly 4 points given.
	// Algorithm: Drawing a Bezier curve is simple. We can sample any point between gamma(0) to
	// gamma(1) at t by simply calculating G * B * T(t), where T(t) is previously defined, B is the
	// Bezier basis/spline matrix (previously defined as well) and G or the geometry matrix can be
	// crafted from the points. Take different samples of gamma(t) by starting t from 0.0, going upto
	// 1.0 inclusive and increasing the value of 't' in every step by 'samplingInterval' parameter.
	// Default 'samplingInterval' is set to 0.001 (1000 samples) in the associated header file. A
	// reference to the original image is returned.
	//
	// [Note] After successful drawing, if your curve is drawn side ways instead of topside up, just
	// switch the X and Y rows in the Geometry matrix G.

	// ---------------- Insert Code Here ----------------
	blaze::StaticMatrix<double, 2, 4> G = {
			{points[0].X, points[1].X, points[2].X, points[3].X},
			{points[0].Y, points[1].Y, points[2].Y, points[3].Y}};
	auto GB = G * BezierSplineMatrix;
	for (double i = 0.0; i <= 1.0; i += samplingInterval)
	{
		auto T = GetMonomialBasis(i);
		auto GBT = GB * T;
		if (GBT[0] < 0.0 || GBT[0] > 512.0)
			return image;
		if (GBT[1] < 0.0 || GBT[1] > 512.0)
			return image;
		image.Pixel(GBT[1], GBT[0]) = color;
	}
	return image;
}

Image &DrawBSplineSegment(Image &image, const std::vector<Point> &points, const Color &color, double samplingInterval)
{
	// ToDo: Draw a Cubic BSpline curve between the points. There will always be exactly 4 points given.
	// Algorithm: Draw using the exact same algorithm as the one from Bezier Curve. Just use the
	// basis/spline matrix for Cubic BSpline instead. Default 'samplingInterval' is set to 0.001
	// (1000 samples) in the associated header file. A reference to the original image is returned.
	//
	// [Note] After successful drawing, if your curve is drawn side ways instead of topside up, just
	// switch the X and Y rows in the Geometry matrix G.

	// ---------------- Insert Code Here ----------------
	blaze::StaticMatrix<double, 2, 4> G = {
			{points[0].X, points[1].X, points[2].X, points[3].X},
			{points[0].Y, points[1].Y, points[2].Y, points[3].Y}};
	auto GB = G * BsplineSplineMatrix;
	for (double i = 0.0; i <= 1.0; i += samplingInterval)
	{
		auto T = GetMonomialBasis(i);
		auto GBT = GB * T;
		if (GBT[0] < 0.0 || GBT[0] > 512.0)
			return image;
		if (GBT[1] < 0.0 || GBT[1] > 512.0)
			return image;
		image.Pixel(GBT[1], GBT[0]) = color;
	}
	return image;
}

Image &DrawBSplineCurve(Image &image, const std::vector<Point> &points, const Color &color, double samplingInterval)
{
	// ToDo: Draw a Cubic BSpline curve for 4 or more points.
	// Algorithm: Just keep on making sets of 4 points by moving the window by a single point
	// at every stage and utilize the previously defined DrawBSplineSegment function to draw
	// the curves. Default 'samplingInterval' is set to 0.001 (1000 samples) in the associated
	// header file. A reference to the original image is returned.

	// ---------------- Insert Code Here ----------------
	for (int i = 0; i <= points.size() - 4; i++)
	{
		std::vector<Point> segment = {points[i], points[i + 1], points[i + 2], points[i + 3]};
		DrawBSplineSegment(image, segment, color);
	}
	return image;
}

Image &DrawCurve(Image &image, CurveType curveType, const std::vector<Point> &points,
								 int circleRadius, const Color &curveColor, const Color &lineColor, const Color &circleColor, double samplingInterval)
{
	for (const auto &point : points)
	{
		DrawCircle(image, point, circleRadius, circleColor);
	}

	for (size_t i = 1; i < points.size(); i++)
	{
		DrawLine(image, points[i - 1], points[i], lineColor);
	}

	switch (curveType)
	{
	case CurveType::BEZIER:
		DrawBezierCurve(image, points, curveColor, samplingInterval);
		break;

	case CurveType::BSPLINE:
		DrawBSplineCurve(image, points, curveColor, samplingInterval);
		break;

	default:
		break;
	}

	return image;
}