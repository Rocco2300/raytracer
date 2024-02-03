#include "Image.hpp"

Image::Image(uint32_t width, uint32_t height) {
    m_width = width;
    m_height = height;

    m_data.resize(width * height);
}

uint8_t* Image::getData() {
    return reinterpret_cast<uint8_t*>(m_data.data());
}

Color* Image::getPixelData() {
    return m_data.data();
}

void Image::setPixel(uint32_t x, uint32_t y, Color color) {
    const uint32_t index = y * m_width + x;
    auto& pixel = m_data.at(index);
    pixel = color;
}
