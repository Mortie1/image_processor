#include "crop.h"

void Crop::Apply(std::string old_file_name, std::string new_file_name) {
    BMP old_image(old_file_name.c_str());
    BMP new_image(width_, height_);
    int32_t old_image_height = old_image.bmp_info_header.height;
    for (int32_t y = 0; y < height_; ++y) {
        for (int32_t x = 0; x < width_; ++x) {
            Colors clrs_old(old_image, x, old_image_height - 1 - y);
            Colors clrs_new(new_image, x, height_ - 1 - y);
            clrs_new.blue = clrs_old.blue;
            clrs_new.red = clrs_old.red;
            clrs_new.green = clrs_old.green;
            }
    }
    new_image.write(new_file_name.c_str());
}