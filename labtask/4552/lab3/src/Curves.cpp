#include "Curves.h"
#include "blaze/Blaze.h"

// The following section of functions and constants should be done by the students
const auto Tfunc = [](double t)
{ 
    return blaze::StaticVector<double, 4UL>{1, t, t * t, t * t * t};
};

const blaze::StaticMatrix<double, 4UL, 4UL> B_Bezier =
{
    {1.0, -3.0,  3.0, -1.0},
    {0.0,  3.0, -6.0,  3.0},
    {0.0,  0.0,  3.0, -3.0},
    {0.0,  0.0,  0.0,  1.0}
};

const blaze::StaticMatrix<double, 4UL, 4UL> B_BSpline =
{
    {1.0 / 6.0, -3.0 / 6.0,  3.0 / 6.0, -1.0 / 6.0},
    {4.0 / 6.0,  0.0 / 6.0, -6.0 / 6.0,  3.0 / 6.0},
    {1.0 / 6.0,  3.0 / 6.0,  3.0 / 6.0, -3.0 / 6.0},
    {0.0 / 6.0,  0.0 / 6.0,  0.0 / 6.0,  1.0 / 6.0}
};
// The above section of functions and constants should be done by the students

Image& DrawCircle(Image& image, const Point& point, int radius, const Color& color)
{
    // Perform bounds checking
    for(int i = point.Y - radius; i <= point.Y + radius; i++)
    {
        if(i < 0 || i > image.GetHeight()) continue;
        for(int j = point.X - radius; j <= point.X + radius; j++)
        {
            if(j < 0 || j > image.GetWidth()) continue;
            double distFromCenter = std::sqrt((i - point.Y) * (i - point.Y) + (j - point.X) * (j - point.X));
            if(distFromCenter <= radius)
            {
                image.Pixel(i, j) = color;
            }
        }
    }
    return image;
}

Image& DrawLineLow(Image& image, const Point& p0, const Point& p1, const Color& color)
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
        if(y >= 0 && y <= image.GetHeight() && x >= 0 && x <= image.GetWidth())
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

Image& DrawLineHigh(Image& image, const Point& p0, const Point& p1, const Color& color)
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
        if (y >= 0 && y <= image.GetHeight() && x >= 0 && x <= image.GetWidth())
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

Image& DrawLine(Image& image, const Point& p0, const Point& p1, const Color& color)
{
    if (abs(p1.Y - p0.Y) < abs(p1.X - p0.X))
    {
        if (p0.X > p1.X)
        {
            return DrawLineLow(image, p1, p0, color);
        }
        else return DrawLineLow(image, p0, p1, color);
    }
    else
    {
        if (p0.Y > p1.Y)
        {
            return DrawLineHigh(image, p1, p0, color);
        }
        else return DrawLineHigh(image, p0, p1, color);
    }
    return image;
}

Image& DrawBezierCurve(Image& image, const std::vector<Point>& points, const Color& color, double samplingInterval)
{
    blaze::StaticMatrix<double, 2UL, 4UL> G =
    {
        {points[0].X, points[1].X, points[2].X, points[3].X},
        {points[0].Y, points[1].Y, points[2].Y, points[3].Y}
    };

    for(double t = 0.0; t <= 1.0; t += samplingInterval)
    {
        auto P = G * B_Bezier * Tfunc(t);
        if(P[0] >= 0 && P[0] <= image.GetHeight() &&
           P[1] >= 0 && P[1] <= image.GetWidth())
        {
            image.Pixel(P[1], P[0]) = color;
        }
    }
    return image;
}

Image& DrawBSplineSegment(Image& image, const std::vector<Point>& points, const Color& color, double samplingInterval)
{
    blaze::StaticMatrix<double, 2UL, 4UL> G =
    {
        {points[0].X, points[1].X, points[2].X, points[3].X},
        {points[0].Y, points[1].Y, points[2].Y, points[3].Y}
    };

    for(double t = 0.0; t <= 1.0; t += samplingInterval)
    {
        auto P = G * B_BSpline * Tfunc(t);
        if(P[0] >= 0 && P[0] <= image.GetHeight() &&
           P[1] >= 0 && P[1] <= image.GetWidth())
        {
            image.Pixel(P[1], P[0]) = color;
        }
    }
    return image;
}

Image& DrawBSplineCurve(Image& image, const std::vector<Point>& points, const Color& color, double samplingInterval)
{
    for(size_t i = 3; i < points.size(); ++i)
    {
        DrawBSplineSegment(image, std::vector{points[i - 3], points[i - 2], points[i - 1], points[i]}, color, samplingInterval);
    }
    return image;
}

Image& DrawCurve(Image& image, CurveType curveType, const std::vector<Point>& points, 
    int circleRadius, const Color& curveColor, const Color& lineColor, const Color& circleColor, double samplingInterval)
{
    for(const auto& point : points)
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