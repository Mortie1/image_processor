#pragma once

#include "filter.h"


class Crop : public Filter {
public:
    Crop(int32_t width, int32_t height) : width_(width), height_(height) {}

    void Apply(std::string old_file_name, std::string new_file_name) override;


private:
    int32_t width_;
    int32_t height_;
};