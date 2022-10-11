#include <iostream>

#include "Ray.h"
#include "Image.h"
#include "HittableList.h"
#include "Sphere.h"
#include "Camera.h"
#include "LinearGradient.h"
#include "Light.h"

const LinearGradient BACKGRADIENT{ Color3{0.6, 0.5, 0.65}, Color3{0.1, 0.1, 0.1}};

Color3 RayColor(const Ray& r, const Camera& camera, const Hittable& world, const std::vector<Light>& lights)
{
    HitRecord rec;
    if (world.Hit(r, 0.001, INF, rec))
    {
        //return 0.5 * (rec.Normal() + Color3{ 1.0, 1.0, 1.0 });
        return rec.MaterialPtr->Shade(rec, camera, lights);
    }
    else
    {
        Vec3 unitDirection = UnitVector(r.Direction());
        auto t = 0.5 * (unitDirection[DirY] + 1.0);
        //return (1.0 - t) * Color3 { 1.0, 1.0, 1.0 } + t * Color3{ 0.5, 0.7, 1.0 };
        return BACKGRADIENT.At(t);
    }
}

int main()
{        
    // Image
    constexpr auto aspectRatio = 16.0 / 9.0;
    constexpr int imageWidth = 720;
    constexpr int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    constexpr int samplesPerPixel = 100;

    Image image{ imageWidth, imageHeight, Color{0, 0, 0} };

    // World
    
    //  |- Lights
    const Point3 lightLocation{ 1.5, 2.0, -1.2 };
    std::vector<Light> lights = {
        Light{ lightLocation, Color3{1.0, 1.0, 1.0}, 1.0, 0.0}
    };

    //  |- Materials
    std::shared_ptr<Material> lightMaterial = std::make_shared<Flat>(Color3{ 1.0, 1.0, 1.0 });
    std::shared_ptr<Material> sphereMaterialFlat = std::make_shared<Flat>(Color{ 246, 74, 138 });
    std::shared_ptr<Material> sphereMaterialLambert = std::make_shared<Lambert>(Color3{ 0.2, 0.4, 0.9 });
    std::shared_ptr<Material> sphereMaterialPhong = std::make_shared<Phong>(Color3{ 0.1, 0.1, 0.1 }, Color3{0.2, 0.4, 0.1}, 0.8);
    std::shared_ptr<Material> sphereMaterialBlinn = std::make_shared<BlinnPhong>(Color3{ 0.1, 0.1, 0.1 }, Color3{0.9, 0.8, 0.1}, 0.95);
    
    //  |- Items
    HittableList world{
        std::make_shared<Sphere>(lightLocation, 1.0, lightMaterial),
        std::make_shared<Sphere>(Point3{-1.2,     0.0, -2.0},    0.5, sphereMaterialFlat),
        std::make_shared<Sphere>(Point3{ 0.0,     0.0, -2.0},    0.5, sphereMaterialBlinn),
        std::make_shared<Sphere>(Point3{ 1.2,     0.0, -2.0},    0.5, sphereMaterialLambert),
        std::make_shared<Sphere>(Point3{ 0.0, -1000.5, -2.0}, 1000.0, sphereMaterialPhong)
    };

    // Camera

    Camera renderCam;

    // Render
    
    for (int j = imageHeight - 1; j >= 0; j--)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; i++)
        {
            Color3 pixelColor{ 0.0, 0.0, 0.0 };
            for (int s = 0; s < samplesPerPixel; s++)
            {
                double u = (i + RandomDouble()) / (imageWidth - 1);
                double v = (j + RandomDouble()) / (imageHeight - 1);

                Ray r = renderCam.GetRay(u, v);

                pixelColor += RayColor(r, renderCam, world, lights);
            }
            image(i, j) = pixelColor / samplesPerPixel;
        }
    }
    std::cerr << "\nDone.\n";

    image.Write("Out.png");

    return 0;
}