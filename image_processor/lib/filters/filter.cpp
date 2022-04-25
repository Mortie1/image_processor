#include "filter.h"

void Filter::ApplyMatrix(const std::vector<std::vector<int32_t>>& matrix, std::string old_file_name, std::string new_file_name) {

    BMP old_image(old_file_name.c_str()), new_image(old_image.bmp_info_header.width, old_image.bmp_info_header.height);
    int32_t center = matrix.size() / 2;
    int32_t size = matrix.size();

    for (int32_t y = 0; y < old_image.bmp_info_header.height; ++y) {
        for (int32_t x = 0; x < old_image.bmp_info_header.width; ++x) {

            int32_t new_blue = 0, new_red = 0, new_green = 0;

            for (int32_t i = 0; i < size; ++i) {
                for (int32_t j = 0; j < size; ++j) {

                    Colors clrs_old(old_image, std::max(std::min(x + i - center, old_image.bmp_info_header.width - 1), 0), std::max(std::min(y + i - center, old_image.bmp_info_header.height - 1), 0));
                    new_red += int32_t(clrs_old.red) * matrix[i][j];
                    new_green += int32_t(clrs_old.green) * matrix[i][j];
                    new_blue += int32_t(clrs_old.blue) * matrix[i][j];
                }
            }

            Colors clrs_new(new_image, x, y);

            clrs_new.blue = uint8_t(std::min(int(std::max(new_blue, 0)), UINT8_MAX));
            clrs_new.green = uint8_t(std::min(int(std::max(new_green, 0)), UINT8_MAX));
            clrs_new.red = uint8_t(std::min(int(std::max(new_red, 0)), UINT8_MAX));
        }
    }
    new_image.write(new_file_name.c_str());
}




void Filter::ApplyMatrix(const std::vector<std::vector<float>>& matrix, std::string old_file_name, std::string new_file_name) {

    BMP old_image(old_file_name.c_str()), new_image(old_image.bmp_info_header.width, old_image.bmp_info_header.height);
    int32_t center = matrix.size() / 2;
    int32_t size = matrix.size();

    for (int32_t y = 0; y < old_image.bmp_info_header.height; ++y) {
        for (int32_t x = 0; x < old_image.bmp_info_header.width; ++x) {

            float new_blue = 0, new_red = 0, new_green = 0;

            for (int32_t i = 0; i < size; ++i) {
                for (int32_t j = 0; j < size; ++j) {

                    Colors clrs_old(old_image, std::max(std::min(x + i - center, old_image.bmp_info_header.width - 1), 0), std::max(std::min(y + i - center, old_image.bmp_info_header.height - 1), 0));
                    new_red += int32_t(clrs_old.red) * matrix[i][j];
                    new_green += int32_t(clrs_old.green) * matrix[i][j];
                    new_blue += int32_t(clrs_old.blue) * matrix[i][j];
                }
            }

            Colors clrs_new(new_image, x, y);

            clrs_new.blue = uint8_t(std::min(int(std::max(new_blue, float(0))), UINT8_MAX));
            clrs_new.green = uint8_t(std::min(int(std::max(new_green, float(0))), UINT8_MAX));
            clrs_new.red = uint8_t(std::min(int(std::max(new_red, float(0))), UINT8_MAX));
        }
    }
    new_image.write(new_file_name.c_str());
}
