#include "blur.h"

void Blur::Apply(std::string old_file_name, std::string new_file_name) {
    BMP old_image(old_file_name.c_str());
    BMP new_image(old_image.bmp_info_header.width, old_image.bmp_info_header.height);
    int32_t matrix_size = std::ceil(sigma_ * 6 + 1);
    int32_t center = matrix_size / 2;
    std::vector<std::vector<float>> matrix(matrix_size, std::vector<float>(matrix_size, 0));
    for (int32_t y = 0; y < matrix_size; ++y) {
        for (int32_t x = 0; x < matrix_size; ++x) {
            matrix[y][x] = (1.0 / (2.0 * M_PI * pow(sigma_, 2)))/ exp( (pow((x - center), 2) + pow((y - center), 2)) / (2 * pow(sigma_, 2)));
        }
    }
    Filter::ApplyMatrix(matrix, old_file_name, new_file_name);
}