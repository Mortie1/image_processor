#pragma once
#include <vector>
#include <cstdint>
#include "../BMP/BMP.h"


class Colors {
public:
    uint8_t & red;
    uint8_t & green;
    uint8_t & blue;
    BMP & bmp;
    Colors(BMP & bmp, const int32_t x, const int32_t y);


};