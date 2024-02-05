#include "Image.hpp"

#include <iostream>

Image::Image(uint32_t width, uint32_t height) {
    m_width  = width;
    m_height = height;

    m_data.resize(width * height * 3);
}

uint8_t* Image::getData() { 
    std::clog << (void*)m_data.data() << std::endl; 
    return &m_data[0]; 
}

void Image::setPixel(uint32_t x, uint32_t y, Color color) {
    const uint32_t index = (y * m_width + x) * 3;
    m_data[index + 0]    = color.r;
    m_data[index + 1]    = color.g;
    m_data[index + 2]    = color.b;
}
