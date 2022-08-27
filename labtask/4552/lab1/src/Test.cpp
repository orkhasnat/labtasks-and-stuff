#include "Vec3.h"

#define COLORED_TESTS
#include "DummyTests.h"

#include <cmath>

TESTS_BEGIN

TEST_UNIT("Getters and Setters")
{
    Vec3 v;
    v.x() = 2.0;
    v.y() = 3.0;
    v.z() = 4.0;

    TEST_ASSERT(v.x() == 2.0 && v.y() == 3.0 && v.z() == 4.0);
}

TEST_UNIT("Equality and Inequality")
{
    Vec3 v;
    v.x() = 2.0;
    v.y() = 3.0;
    v.z() = 4.0;

    Vec3 v1(2.0, 3.0, 4.0);
    Vec3 v2;

    TEST_ASSERT(v == v1 && v != v2);
}

TEST_UNIT("Unary Minus")
{
    TEST_REQUIRES("Equality and Inequality");

    Vec3 v(1.0, 5.5, 2.2);
    
    TEST_ASSERT(v == -(-v));
}

TEST_UNIT("Index Operator Non Const")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v(1.0, 2.0, 3.0);
    Vec3 vref(0.0, 0.0, 0.0);
    v[0] = 0.0;
    v[1] = 0.0;
    v[2] = 0.0;
    
    TEST_ASSERT(v == vref);
}

TEST_UNIT("Index Operator Const")
{
    TEST_REQUIRES("Getters and Setters");
    
    Vec3 v{1.0, 2.0, 3.0};
    
    TEST_ASSERT(v.x() == v[0] && v.y() == v[1] && v.z() == v[2]);
}

TEST_UNIT("+= with Vec3")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{1.0, 2.0, 3.0};
    Vec3 v2{2.0, 4.0, 6.0};
    v1 += v1;
    
    TEST_ASSERT(v1 == v2);
}

TEST_UNIT("*= with double")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{1.0, 2.0, 3.0};
    Vec3 v2{2.0, 4.0, 6.0};
    v1 *= 2.0;
    
    TEST_ASSERT(v1 == v2);
}

TEST_UNIT("/= with double")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{2.0, 4.0, 6.0};
    Vec3 v2{1.0, 2.0, 3.0};
    v1 /= 2.0;
    
    TEST_ASSERT(v1 == v2);
}

TEST_UNIT("+ with Vec3")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{2.0, 4.0, 6.0};
    Vec3 v2{1.0, 2.0, 3.0};
    Vec3 v3{3.0, 6.0, 9.0};
    
    TEST_ASSERT(v1 + v2 == v3);
}

TEST_UNIT("+ with double")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{2.0, 4.0, 6.0};
    double d = 4.5;
    Vec3 v2{6.5, 8.5, 10.5};
    
    
    TEST_ASSERT(v1 + d == v2);
}

TEST_UNIT("- with Vec3")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{3.0, 6.0, 9.0};
    Vec3 v2{2.0, 4.0, 6.0};
    Vec3 v3{1.0, 2.0, 3.0};
    
    TEST_ASSERT(v1 - v2 == v3);
}

TEST_UNIT("- with double")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{6.5, 8.5, 10.5};
    double d = 4.5;
    Vec3 v2{2.0, 4.0, 6.0};
    
    
    TEST_ASSERT(v1 - d == v2);
}

TEST_UNIT("* with Vec3")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{2.0, 4.0, 6.0};
    Vec3 v2{1.0, 2.0, 3.0};
    Vec3 v3{2.0, 8.0, 18.0};
    
    TEST_ASSERT(v1 * v2 == v3);
}

TEST_UNIT("* with double")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{2.0, 4.0, 6.0};
    double d = 4.5;
    Vec3 v2{9.0, 18.0, 27.0};
    
    
    TEST_ASSERT(v1 * d == v2);
}

TEST_UNIT("/ with Vec3")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{2.0, 8.0, 18.0};
    Vec3 v2{1.0, 2.0, 3.0};
    Vec3 v3{2.0, 4.0, 6.0};
    
    TEST_ASSERT(v1 / v2 == v3);
}

TEST_UNIT("/ with double")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{9.0, 18.0, 27.0};
    double d = 4.5;
    Vec3 v2{2.0, 4.0, 6.0};
    
    
    TEST_ASSERT(v1 / d == v2);
}

TEST_UNIT("Length Squared")
{   
    Vec3 v{2.0, 3.0, 4.0};
    TEST_ASSERT(DOUBLE_EQ(v.LengthSquared(), 29.0));
}

TEST_UNIT("Length")
{   
    Vec3 v{2.0, 3.0, 4.0};
    
    TEST_ASSERT(DOUBLE_EQ(v.Length(),std::sqrt(29.0)));
}

TEST_UNIT("Static Dot")
{
    Vec3 v1{2.0, 4.0, 6.0};
    Vec3 v2{1.0, 2.0, 3.0};

    TEST_ASSERT(DOUBLE_EQ(Vec3::Dot(v1, v2), 28.0));
}

TEST_UNIT("Vec3 Dot")
{
    Vec3 v1{2.0, 4.0, 6.0};
    Vec3 v2{1.0, 2.0, 3.0};

    TEST_ASSERT(DOUBLE_EQ(v1.Dot(v2), 28.0));
}

TEST_UNIT("Static Cross")
{
    TEST_REQUIRES("Equality and Inequality");

    Vec3 v1{2.0, -3.0, 1.0};
    Vec3 v2{4.0, -1.0, 5.0};
    Vec3 v3{-14.0, -6.0, 10.0};

    TEST_ASSERT(Vec3::Cross(v1, v2) == v3);
}

TEST_UNIT("Vec3 Cross")
{
     TEST_REQUIRES("Equality and Inequality");

    Vec3 v1{2.0, -3.0, 1.0};
    Vec3 v2{4.0, -1.0, 5.0};
    Vec3 v3{-14.0, -6.0, 10.0};

    TEST_ASSERT(v1.Cross(v2) == v3);
}

TEST_UNIT("Near Zero")
{
    double nZ = 1.99 - (1.0 + 0.99);
    Vec3 v{nZ, nZ, nZ};

    TEST_ASSERT(v.NearZero());
}

TEST_UNIT("Random Vec3 [0.0, 1)")
{
    auto v = Vec3::Random();

    TEST_ASSERT(v.x() >= 0.0 && v.x() < 1.0 && 
                v.y() >= 0.0 && v.y() < 1.0 &&
                v.z() >= 0.0 && v.z() < 1.0);
}

TEST_UNIT("Random Vec3 [min, max)")
{
    double min = 2.0;
    double max = 4.5;
    auto v = Vec3::Random(min, max);

    TEST_ASSERT(v.x() >= min && v.x() < max && 
                v.y() >= min && v.y() < max &&
                v.z() >= min && v.z() < max);
}

TEST_UNIT("double + Vec3")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{2.0, 4.0, 6.0};
    double d = 4.5;
    Vec3 v2{6.5, 8.5, 10.5};
    
    
    TEST_ASSERT(d + v1 == v2);
}

TEST_UNIT("double - Vec3")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{6.5, 8.5, 10.5};
    double d = 4.5;
    Vec3 v2{2.0, 4.0, 6.0};
    
    
    TEST_ASSERT(d - v1 == v2);
}

TEST_UNIT("double * Vec3")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{2.0, 4.0, 6.0};
    double d = 4.5;
    Vec3 v2{9.0, 18.0, 27.0};
    
    
    TEST_ASSERT(d * v1 == v2);
}

TEST_UNIT("double / Vec3")
{
    TEST_REQUIRES("Equality and Inequality");
    
    Vec3 v1{9.0, 18.0, 27.0};
    double d = 4.5;
    Vec3 v2{2.0, 4.0, 6.0};
    
    
    TEST_ASSERT(d / v1 == v2);
}

TEST_UNIT("Unit Vector")
{
    TEST_REQUIRES("Equality and Inequality");

    Vec3 v1{1.0, 2.0, 3.0};
    Vec3 v1unit{0.267261241912424, 0.534522483824849, 0.801783725737273};

    TEST_ASSERT(UnitVector(v1) == v1unit);
}

TEST_UNIT("Angle")
{
    TEST_REQUIRES("Equality and Inequality");

    Vec3 v1{1.0, 0.0, 0.0};
    Vec3 v2{0.0, 2.0, 2.0};
    double angleV1V2 = 1.570796326794897;
    TEST_ASSERT(DOUBLE_EQ(Angle(v1, v2), angleV1V2));
}

TESTS_END