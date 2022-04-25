#include "grayscale.h"

void GreyScale::Apply(std::string old_file_name, std::string new_file_name) {
    BMP old_image(old_file_name.c_str());
    BMP new_image(old_image.bmp_info_header.width, old_image.bmp_info_header.height);
    for (int32_t y = 0; y < old_image.bmp_info_header.height; ++y) {
        for (int32_t x = 0; x < old_image.bmp_info_header.width; ++x) {
            Colors clrs_old(old_image, x, y);
            Colors clrs_new(new_image, x, y);
            uint8_t grey = clrs_old.red * 0.299 + clrs_old.green * 0.587 + clrs_old.blue * 0.114;
            clrs_new.blue = grey;
            clrs_new.green = grey;
            clrs_new.red = grey;
        }
    }
    new_image.write(new_file_name.c_str());
}