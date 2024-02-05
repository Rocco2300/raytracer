#ifndef RAYTRACER_IMAGE_HPP
#define RAYTRACER_IMAGE_HPP

#include <glm/glm.hpp>

#include <vector>

typedef glm::vec<3, uint8_t> Color;

class Image {
private:
    uint32_t m_width;
    uint32_t m_height;

    std::vector<uint8_t> m_data;

public:
    Image() = default;
    Image(uint32_t width, uint32_t height);

    uint8_t* getData();

    void setPixel(uint32_t x, uint32_t y, Color color);
};

#endif
