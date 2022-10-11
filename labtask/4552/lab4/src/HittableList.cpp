#include "HittableList.h"

HittableList::HittableList(const std::initializer_list<ref_Hittable>& initList)
{
    for (auto& object : initList)
    {
        Add(object);
    }
}

bool HittableList::Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const
{
    HitRecord tempRecord;
    bool hitAnything = false;
    auto closestSoFar = t_max;

    for (const auto& object : m_Objects)
    {
        if (object->Hit(r, t_min, closestSoFar, tempRecord))
        {
            hitAnything = true;
            closestSoFar = tempRecord.t;
            rec = tempRecord;
        }
    }

    return hitAnything;
}