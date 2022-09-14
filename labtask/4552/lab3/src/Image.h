#pragma once

#include <cinttypes>
#include <string>

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

    inline void Write(const std::string& path) { Write(path.c_str()); }
    void Write(const char *path);
};