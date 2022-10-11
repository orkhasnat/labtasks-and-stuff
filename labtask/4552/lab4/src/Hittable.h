#pragma once

#include "Material.h"
#include "Ray.h"

struct HitRecord
{
private:
	bool m_FrontFace;
	Vec3 m_Normal{0.0, 0.0, 1.0};

public:
	Point3 P{0.0, 0.0, 0.0};
	double t;
	std::shared_ptr<Material> MaterialPtr;
	inline bool FrontFace() const { return m_FrontFace; }
	inline const Vec3& Normal() const { return m_Normal; }

	inline void SetFaceNormal(const Ray& r, const Vec3& outwardNormal)
	{
		m_FrontFace = blaze::dot(r.Direction(), outwardNormal) < 0.0;
		m_Normal = m_FrontFace ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
public:
	virtual bool Hit(const Ray& r, double tMin, double tMax, HitRecord& rec) const = 0;
};