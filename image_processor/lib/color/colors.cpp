#include "colors.h"

Colors::Colors(BMP & image, const int32_t x, const int32_t y) : red(image.data[image.bmp_info_header.bit_count / 8 * (y * image.bmp_info_header.width + x) + 2]),
                                                                                                                    green(image.data[image.bmp_info_header.bit_count / 8 * (y * image.bmp_info_header.width + x) + 1]),
                                                                                                                    blue(image.data[image.bmp_info_header.bit_count / 8 * (y * image.bmp_info_header.width + x) + 0]), bmp(image) {
}