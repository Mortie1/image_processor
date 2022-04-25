#pragma once

#include "filter.h"


#include <cmath>

class Blur: public Filter{
public:

    Blur(float sigma) : sigma_(sigma) {
    }

    void Apply(std::string old_file_name, std::string new_file_name) override;

private:

    float sigma_;
};