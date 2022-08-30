#include "Image.h"
#include "Curves.h"

int main()
{
    Image image1{512, 512};
    Image image2{512, 512};
    Image image3{512, 512};

    std::vector<Point> points{
        {5, 5},
        {5, 450},
        {506, 506},
        {506, 5}
    };

    std::vector<Point> points2{
        {145, 195},
        {145, 255},
        { 40, 255},
        { 40,  60},
        {445,  60},
        {445, 450},
        { 40, 450},
        { 40, 380},
        {400, 380}
    };

    DrawCurve(image1, CurveType::BEZIER, points);
    image1.Write("./Bezier.png");

    DrawCurve(image2, CurveType::BSPLINE, points);
    image2.Write("./BSpline.png");
    
    DrawCurve(image3, CurveType::BSPLINE, points2);
    image3.Write("./BSpline2.png");

    return 0;
}