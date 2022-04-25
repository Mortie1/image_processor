#pragma once
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cmath>

#include "../BMP/BMP.h"
#include "../color/colors.h"


class Filter {
public:

    virtual void Apply(std::string old_file_name, std::string new_file_name) = 0; // параметры не обсуждаем

    void ApplyMatrix(const std::vector<std::vector<int32_t>>& matrix, std::string old_file_name, std::string new_file_name);

    void ApplyMatrix(const std::vector<std::vector<float>>& matrix, std::string old_file_name, std::string new_file_name);

};