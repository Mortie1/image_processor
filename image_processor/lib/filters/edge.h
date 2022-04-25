#pragma once
#include "filter.h"
#include "grayscale.h"


class Edge : public Filter{
public:
    Edge(float threshold) : threshold_(threshold) {}

    void Apply(std::string old_file_name, std::string new_file_name) override;

private:
    float threshold_;
};

