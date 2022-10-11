#pragma once

#include <vector>

#include "Vec3.h"

struct HitRecord;
class Light;
class Camera;

class Material
{
public:
	virtual Color3 Shade(const HitRecord& rec, const Camera& camera, const std::vector<Light>& lights) const = 0;
};

class Flat : public Material
{
private:
	Color3 m_Color;

public:
	inline Flat(const Color3 color) : m_Color{ color } {}
	virtual Color3 Shade(const HitRecord& rec, const Camera& camera, const std::vector<Light>& lights) const override;
};

class Lambert : public Material
{
private:
	Color3 m_Color;

public:
	inline Lambert(const Color3& color) : m_Color{ color } {}
	virtual Color3 Shade(const HitRecord& rec, const Camera& camera, const std::vector<Light>& lights) const override;
};

class Phong : public Material
{
private:
	Color3 m_Ambient{0.0, 0.0, 0.0};
	Color3 m_Diffused;
	double m_SpecularStrength{0.5};
	Color3 m_SpecularColor{1.0, 0.0, 0,0};
	double m_Shininess{32};

public:
	inline Phong(const Color3& ambient, const Color3& diffused,
		double specularStrength = 0.5, const Color3& specularColor = Color3{ 1.0, 1.0, 1.0 }, double shininess = 32)
		: m_Ambient{ ambient }, m_Diffused{ diffused }, m_SpecularStrength{ specularStrength },
		m_SpecularColor{ specularColor }, m_Shininess{ shininess } {}

	virtual Color3 Shade(const HitRecord& rec, const Camera& camera, const std::vector<Light>& lights) const override;
};

class BlinnPhong : public Material
{
private:
	Color3 m_Ambient;
	Color3 m_Diffused;
	double m_SpecularStrength;
	Color3 m_SpecularColor;
	double m_Shininess;

public:
	inline BlinnPhong(const Color3& ambient, const Color3& diffused,
		double specularStrength = 0.5, const Color3& specularColor = Color3{ 1.0, 1.0, 1.0 }, double shininess = 32)
		: m_Ambient{ ambient }, m_Diffused{ diffused }, m_SpecularStrength{ specularStrength },
		m_SpecularColor{ specularColor }, m_Shininess{ shininess } {}

	virtual Color3 Shade(const HitRecord& rec, const Camera& camera, const std::vector<Light>& lights) const override;
};