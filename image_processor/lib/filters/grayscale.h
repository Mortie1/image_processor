#pragma once
#include "filter.h"

class GreyScale : public Filter {
public:
    void Apply(std::string old_file_name, std::string new_file_name) override;

};