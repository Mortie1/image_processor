#include "sharp.h"


void Sharp::Apply(std::string old_file_name, std::string new_file_name) {
    std::vector<std::vector<int32_t>> matrix {{0, -1, 0},
                                             {-1, 5, -1},
                                             {0, -1, 0}};
    Filter::ApplyMatrix(matrix, old_file_name, new_file_name);
}