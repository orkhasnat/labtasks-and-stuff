#include "Material.h"
#include "Hittable.h"
#include "Light.h"
#include "Camera.h"

Color3 Flat::Shade(const HitRecord &rec, const Camera &camera, const std::vector<Light> &lights) const
{
    // ToDo: Task 1 ---------------------- FLAT SHADER ----------------------
    // A Flat shader is not dependent on the lights or the camera angles
    // It should just return the flat color of the material
    // Check the class declaration to find out member variables in Material.h > Line 19 onwards

    // return Color3{0.0, 0.0, 0.0};
    return m_Color;
}

Color3 Lambert::Shade(const HitRecord &rec, const Camera &camera, const std::vector<Light> &lights) const
{
    // ToDo: Task 2 ---------------------- LAMBERT SHADER ----------------------
    // A Lambert shader is used for perfectly diffusing objects
    // The color of a Lambert shader is dependent on the light angle and the color of the object
    // The more directly a light is facing towards an object region, the brighter that region would appear
    // Calculate color of each corresponding pixel
    // You can get the overall illuminination by a light by calling the function <lightVariableName>.GetIllumination();
    // Loop for all the lights initially and add up all the values
    // Follow the instructions given in the lab
    // Check the class declaration to find out member variables in Material.h > Line 29 onwards
    
    // auto max = [](double a, double b)
    // {
    //     return a > b ? a : b;
    // };

    Color3 shadedColor{0.0, 0.0, 0.0};
    for (const auto &light : lights)
    {
        // Write per light logic here and add to shadedColor
        shadedColor += blaze::max(blaze::dot(UnitVector(rec.Normal()), UnitVector(light.GetPosition() - rec.P)), 0) * m_Color * light.GetIllumination();
    }
    return shadedColor;
}

Color3 Phong::Shade(const HitRecord &rec, const Camera &camera, const std::vector<Light> &lights) const
{
    // ToDo: Task 3 ---------------------- PHONG SHADER ----------------------
    // A Phong shader is used for shiny objects
    // It is a combination of ambient (like flat shader), diffused (like Lambert shader) and specular highlight (the shiny property)
    // Calculate ambient and diffused parts like before
    // The color of the specular highlight is dependent on the light angle and camera looking angle
    // The they camera ray can directly reflects around the object normal to reach the light, the object will have highest specular highlight
    // The specular strength, specular color and shininess control the highlight
    // Calculate color of each corresponding pixel by adding up ambient, diffused and specular highlight components
    // You can get the overall illuminination by a light by calling the function <lightVariableName>.GetIllumination();
    // Loop for all the lights initially and add up all the values, where each values are sum of different components as well
    // Follow the instructions given in the lab
    // Check the class declaration to find out member variables in Material.h > Line 39 onwards

    Color3 shadedColor{0.0, 0.0, 0.0};
    for (const auto &light : lights)
    {
        // Write per light logic here and add to shadedColor
        Color3 lambertComponent =blaze::max(blaze::dot(UnitVector(rec.Normal()), UnitVector(light.GetPosition() - rec.P)), 0) * m_Diffused * light.GetIllumination();
        
        Color3 ambientComponent = m_Ambient * m_Diffused;
        
        Vec3 ReflectRay = Reflect(UnitVector(camera.GetOrigin()-rec.P),rec.Normal());
        
        double phongSpec = blaze::pow(blaze::max(blaze::dot(UnitVector(ReflectRay) , UnitVector(light.GetPosition()-rec.P)),0),m_Shininess);
        
        Color3 specularComponent= phongSpec * m_SpecularColor * m_SpecularStrength * light.GetIllumination();

        shadedColor+= ambientComponent + lambertComponent + specularComponent;
    }
    return shadedColor;
}

Color3 BlinnPhong::Shade(const HitRecord &rec, const Camera &camera, const std::vector<Light> &lights) const
{
    // ToDo: Task 4 ---------------------- BLINN PHONG SHADER ----------------------
    // A BlinnPhong shader is like Phong shader, but with correction for some errors
    // It is a combination of ambient (like flat shader), diffused (like Lambert shader) and specular highlight (the shiny property)
    // Calculate ambient and diffused parts like before
    // The color of the specular highlight is dependent on the average vector between light angle and camera looking angle, and the surface normal
    // If the average angle and the surface normal of a region aligns perfectly, that object region will have highest specular highlight
    // The specular strength, specular color and shininess control the highlight
    // Calculate color of each corresponding pixel by adding up ambient, diffused and specular highlight components
    // You can get the overall illuminination by a light by calling the function <lightVariableName>.GetIllumination();
    // Loop for all the lights initially and add up all the values, where each values are sum of different components as well
    // Follow the instructions given in the lab
    // Check the class declaration to find out member variables in Material.h > Line 57 onwards

    Color3 shadedColor{0.0, 0.0, 0.0};
    for (const auto &light : lights)
    {
        // Write per light logic here and add to shadedColor
        Color3 lambertComponent =blaze::max(blaze::dot(UnitVector(rec.Normal()), UnitVector(light.GetPosition() - rec.P)), 0) * m_Diffused * light.GetIllumination();
        
        Color3 ambientComponent = m_Ambient * m_Diffused;
        
        // auto ReflectRay = Reflect(UnitVector(camera.GetOrigin()-rec.P),rec.Normal());
        Vec3 blingRay = UnitVector(UnitVector(camera.GetOrigin()-rec.P)+UnitVector(light.GetPosition()-rec.P));
        double blingSpec = blaze::pow(blaze::max(blaze::dot(blingRay,UnitVector(rec.Normal())),0),m_Shininess);

        Color3 specularComponent= blingSpec * m_SpecularColor * m_SpecularStrength * light.GetIllumination();
        shadedColor+= ambientComponent + lambertComponent + specularComponent;

    }
    return shadedColor;
}
