#pragma once

#include <cinttypes>
#include <string>

#include "Vec3.h"
#include "Util.h"

constexpr size_t CHANNELS = 3;
constexpr bool FLIP_IMAGE = true;

struct Color
{
    union 
    {
        uint8_t V[3];
        struct {
            uint8_t R;
            uint8_t G;
            uint8_t B;
        };
    };

    inline Color(uint8_t r, uint8_t g, uint8_t b) : R{r}, G{g}, B{b} {}
    inline Color(uint8_t v) : Color(v, v, v) {}
    inline Color() : Color(0, 0, 0) {}
    
    //inline Color(const Color3& color3) : Color( (255.999 * color3[0]), (255.999 * color3[1]), (255.999 * color3[2])) {}
    
    inline Color(const Color3& color3)
    {
        Color3 clampedColor = blaze::clamp(color3, 0.0, 1.0);
        R = static_cast<uint8_t>(255.999 * clampedColor[0]);
        G = static_cast<uint8_t>(255.999 * clampedColor[1]);
        B = static_cast<uint8_t>(255.999 * clampedColor[2]);
    }

    inline Color& operator=(const Color3& color3)
    {
        Color3 clampedColor = blaze::clamp(color3, 0.0, 1.0);
        R = static_cast<uint8_t>(255.999 * clampedColor[0]);
        G = static_cast<uint8_t>(255.999 * clampedColor[1]);
        B = static_cast<uint8_t>(255.999 * clampedColor[2]);
        return *this;
    }

    inline operator Color3() const
    {
        return Color3{ R / 256.0, G / 256.0, B / 256.0 };
    }

    inline Color operator*(double t) const { return Color( R * t, G * t, B * t ); }
    inline Color operator+(double t) const { return Color( R + t, G + t, B + t ); }
    inline Color operator+(const Color& other) const
    {
        return Color(
            Clamp(R + other.R, 0, 255),
            Clamp(G + other.G, 0, 255),
            Clamp(B + other.B, 0, 255)
        );
    }
    inline uint8_t operator[](size_t index) const { return V[index]; }
    inline uint8_t& operator[](size_t index) { return V[index]; }
};

class Image
{
private:
    uint8_t* m_Buffer;
    size_t m_Width;
    size_t m_Height;

public:
    Image(size_t width, size_t height);
    Image(size_t width, size_t height, const Color &bgColor);
    Image(const Image &other); // Copy CTOR
    Image& operator=(const Image& other); // Copy Assignment
    Image(Image &&other) noexcept; // Move CTOR
    Image& operator=(Image&& other) noexcept; // Move Assignment
    ~Image();

    size_t GetWidth() const { return m_Width; }
    size_t GetHeight() const { return m_Height; }

    Color& Pixel(size_t row, size_t col) const;
    Color& Pixel(size_t row, size_t col);
    inline Color& operator()(size_t x, size_t y) const { return Pixel(y, x); }
    inline Color& operator()(size_t x, size_t y) { return Pixel(y, x); }

    inline void Write(const std::string& path) { Write(path.c_str()); }
    void Write(const char *path);
};