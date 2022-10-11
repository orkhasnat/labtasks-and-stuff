#pragma once

#include "Hittable.h"

#include <memory>
#include <vector>

class HittableList : public Hittable
{
    using ref_Hittable = std::shared_ptr<Hittable>;
private:
    std::vector<ref_Hittable> m_Objects;

public:
    HittableList() {}
    HittableList(const std::initializer_list<ref_Hittable>& initList);

    inline std::vector<ref_Hittable>& GetObjects() { return m_Objects; }

    inline void Clear() { m_Objects.clear(); }
    inline void Add(ref_Hittable object) { m_Objects.push_back(object); }

    virtual bool Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;
};