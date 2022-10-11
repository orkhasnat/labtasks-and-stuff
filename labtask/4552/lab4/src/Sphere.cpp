#include "Sphere.h"

bool Sphere::Hit(const Ray& r, double tMin, double tMax, HitRecord& rec) const
{
    Vec3 oc = r.Origin() - m_Center;
    auto a = blaze::sqrLength(r.Direction());
    auto halfb = blaze::dot(oc, r.Direction());
    auto c = blaze::sqrLength(oc) - m_Radius * m_Radius;

    auto discriminant = halfb * halfb - a * c;
    if (discriminant < 0.0) return false;
    auto sqrtd = blaze::sqrt(discriminant);

    // Find nearest root that lies in the acceptable range
    auto root = (-halfb - sqrtd) / a; // root 1
    if (root < tMin || root > tMax)
    {
        root = (-halfb + sqrtd) / a; // root 2
        if (root < tMin || root > tMax)
            return false;
    }

    rec.t = root;
    rec.P = r.At(root);
    rec.MaterialPtr = m_Material;
    Vec3 outwardNormal = (rec.P - m_Center) / m_Radius;
    rec.SetFaceNormal(r, outwardNormal);

    return true;
}
