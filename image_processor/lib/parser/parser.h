#pragma once

#include "../filters/crop.h"
#include "../filters/negative.h"
#include "../filters/grayscale.h"
#include "../filters/sharp.h"
#include "../filters/edge.h"
#include "../filters/blur.h"
#include "unixpath.h"

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>

struct FilterDescription {
    std::string name;
    std::vector<std::string> parameters;

    void Clear();
};

struct ParseResults {
    std::string in_path;
    std::string out_path;
    std::vector<FilterDescription> filter_descriptions;
};

class ArgParser {
public:
    static ParseResults Parse(int argc, char const * argv[]);
};


std::shared_ptr<Filter> GetPtr(FilterDescription filter_description);