#include "edge.h"

void Edge::Apply(std::string old_file_name, std::string new_file_name) {
        GreyScale gs;
        gs.Apply(old_file_name, new_file_name);
        std::vector<std::vector<int32_t>> matrix {{0, -1, 0},
                                                 {-1, 4, -1},
                                                 {0, -1, 0}};
        Filter::ApplyMatrix(matrix, old_file_name, new_file_name);
        BMP old_image(old_file_name.c_str()), new_image(old_image.bmp_info_header.width, old_image.bmp_info_header.height);
        for (int32_t y = 0; y < old_image.bmp_info_header.height; ++y) {
            for (int32_t x = 0; x < old_image.bmp_info_header.width; ++x) {
                Colors clrs_old(old_image, x, y);
                Colors clrs_new(new_image, x, y);
                if (clrs_old.blue >= uint8_t(threshold_ * 255)) {
                    clrs_new.blue = UINT8_MAX;
                    clrs_new.red = UINT8_MAX;
                    clrs_new.green = UINT8_MAX;
                } else {
                    clrs_new.blue = 0;
                    clrs_new.red = 0;
                    clrs_new.green = 0;
                }
            }
        }
        new_image.write(new_file_name.c_str());
}