#include "Image.h"

#include "stb_image_write.h"
#include <stdexcept>
#include <cstring>

Image::Image(size_t width, size_t height)
    : Image(width, height, Color{0, 0, 0})
{

}

Image::Image(size_t width, size_t height, const Color &bgColor)
    : m_Width{width}, m_Height{height}
{
    m_Buffer = new uint8_t[width * height * CHANNELS];
    for(size_t i = 0; i < height; i++)
    {
        for(size_t j = 0; j < width; j++)
        {
            for(size_t k = 0; k < CHANNELS; k++)
            {
                m_Buffer[i * width * CHANNELS + j * CHANNELS + k] = bgColor[k];
            }
        }
    }
}

Image::Image(const Image &other) // Copy CTOR
{
    delete[] m_Buffer;

    m_Width = other.m_Width;
    m_Height = other.m_Height;

    m_Buffer = new uint8_t[m_Width * m_Height * CHANNELS];

    std::memmove(m_Buffer, other.m_Buffer, sizeof(uint8_t) * m_Width * m_Height * CHANNELS);
}

Image& Image::operator=(const Image& other) // Copy Assignment
{
    delete[] m_Buffer;

    m_Width = other.m_Width;
    m_Height = other.m_Height;

    m_Buffer = new uint8_t[m_Width * m_Height * CHANNELS];

    std::memmove(m_Buffer, other.m_Buffer, sizeof(uint8_t) * m_Width * m_Height * CHANNELS);

    return *this;
}

Image::Image(Image &&other) noexcept // Move CTOR
    : m_Width{ std::move(other.m_Width) }, m_Height{ std::move(other.m_Height) }, m_Buffer{ std::move(other.m_Buffer) }
{

}

Image& Image::operator=(Image&& other) noexcept // Move Assignment
{
    m_Width = std::move(other.m_Width);
    m_Height = std::move(other.m_Height);
    m_Buffer = std::move(other.m_Buffer);

    return * this;
}

Image::~Image()
{
    delete[] m_Buffer;
}

Color& Image::Pixel(size_t row, size_t col) const
{
    if(row < 0 || row > m_Height)
        throw std::out_of_range{"[row] is out of range"};
    else if(col < 0 || col > m_Height)
        throw std::out_of_range{"[col] is out of range"};
    else
        return *( ( Color* )(m_Buffer + (row * m_Width * CHANNELS + col * CHANNELS)) );
}

Color& Image::Pixel(size_t row, size_t col)
{
    if(row < 0 || row > m_Height)
        throw std::out_of_range{"[row] is out of range"};
    else if(col < 0 || col > m_Width)
        throw std::out_of_range{"[col] is out of range"};
    else
        return *( ( Color* )(m_Buffer + (row * m_Width * CHANNELS + col * CHANNELS)) );
}

void Image::Write(const char *path)
{
    if constexpr(FLIP_IMAGE)
    {
        stbi_flip_vertically_on_write(1);
    }
    else stbi_flip_vertically_on_write(0);

    stbi_write_png(path, m_Width, m_Height, CHANNELS, static_cast<void*>(m_Buffer), m_Width * CHANNELS);
}