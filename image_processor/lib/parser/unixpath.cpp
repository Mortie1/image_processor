#include "unixpath.h"
#include "string_view"
#include "string"
#include "iostream"


std::string NormalizePath(std::string_view current_working_dir, std::string_view path) {
    std::string result {current_working_dir};
    size_t i = 0;
    size_t path_size = path.size();
    while (i < path.size() - 1) {
        if (path[i] == '.' && path[i + 1] == '.') {
            size_t j = result.size();
            while (result[j - 1] != '/' && j > 0) {
                result.pop_back();
                --j;
            }
            if (result.size() != 1) {
                result.pop_back();
            }
            i += 3;
        } else if (path[i] == '.' && path[i + 1] != '.') {
            i += 2;

        } else if (path[i] == '/') {
            ++i;
        } else if (path[i] != '.' && path[i] != '/') {
            try {
                if (result[result.size() - 1] != '/') {
                    result.push_back('/');
                }
            } catch (const std::bad_alloc& e) {
                result = "/";
            }
            while (i < path_size && path[i] != '/') {
                try {
                    result.push_back(path[i]);
                    ++i;
                } catch (const std::bad_alloc& e) {
                    result = "error!!!";
                }
            }
        }
    }

    return result;
}
