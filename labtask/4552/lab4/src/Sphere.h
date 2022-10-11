#pragma once

#include "Hittable.h"

class Sphere : public Hittable
{
private:
	Point3 m_Center;
	double m_Radius;
	std::shared_ptr<Material> m_Material;

public:
	inline Sphere(const Point3& center, double radius, std::shared_ptr<Material> material)
		: m_Center{ center }, m_Radius{ radius }, m_Material{ material } {};
	inline Sphere() : Sphere( Point3{ 0.0, 0.0, 0.0 }, 1, std::make_shared<Lambert>(Color3{1.0, 0.0, 0.0}) ) {}

	inline const Point3& Center() const { return m_Center; }
	inline double Radius() const { return m_Radius; }

	virtual bool Hit(const Ray& r, double tMin, double tMax, HitRecord& rec) const override;
};