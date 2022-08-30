#pragma once

#include <vector>
#include "Image.h"

struct Point
{
    double X;
    double Y;

    inline Point(double x, double y) : X{x}, Y{y} {}
    inline Point() : Point{0.0, 0.0} {}
};

static const Color Pink{250, 180, 180};
static const Color Blue{0, 0, 255};
static const Color Green{0, 255, 100};

enum class CurveType
{
    BEZIER, BSPLINE
};

Image& DrawCircle(Image& image, const Point& point, int radius);
static Image& DrawLineLow(Image& image, const Point& p0, const Point& p1, const Color& color);
static Image& DrawLineHigh(Image& image, const Point& p0, const Point& p1, const Color& color);
Image& DrawLine(Image& image, const Point& p0, const Point& p1, const Color& color = Green);
Image& DrawBezierCurve(Image& image, const std::vector<Point>& points, const Color& color, double samplingInterval = 0.001);
Image& DrawBSplineSegment(Image& image, const std::vector<Point>& points, const Color& color, double samplingInterval = 0.001);
Image& DrawBSplineCurve(Image& image, const std::vector<Point>& points, const Color& color, double samplingInterval = 0.001);
Image& DrawCurve(Image& image, CurveType curveType, const std::vector<Point>& points, 
    int circleRadius = 5, const Color& curveColor = Blue, const Color& lineColor = Green, const Color& circleColor = Pink, double samplingInterval = 0.001);