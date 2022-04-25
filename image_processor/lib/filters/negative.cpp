#include "negative.h"

void Negative::Apply(std::string old_file_name, std::string new_file_name) {
    BMP old_image(old_file_name.c_str());
    BMP new_image(old_image.bmp_info_header.width, old_image.bmp_info_header.height);
    for (int32_t y = 0; y < old_image.bmp_info_header.height; ++y) {
        for (int32_t x = 0; x < old_image.bmp_info_header.width; ++x) {
            Colors clrs_old(old_image, x, y);
            Colors clrs_new(new_image, x, y);
            uint8_t neg_blue = UINT8_MAX - clrs_old.blue;
            uint8_t neg_green = UINT8_MAX - clrs_old.green;
            uint8_t neg_red = UINT8_MAX - clrs_old.red;
            clrs_new.blue = neg_blue;
            clrs_new.green = neg_green;
            clrs_new.red = neg_red;
        }
    }
    new_image.write(new_file_name.c_str());
}