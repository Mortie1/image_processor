#include "parser.h"


void FilterDescription::Clear() {
    name.clear();
    parameters.clear();
}


ParseResults ArgParser::Parse(int argc, char const * argv[]) {
    std::vector<FilterDescription> filter_descriptions;
    ParseResults result;
    result.in_path = "";
    result.out_path = "";
    result.filter_descriptions = filter_descriptions;
    if (argc == 2) {
        throw std::runtime_error("Error! Not enough arguments provided");
    }
    result.in_path = NormalizePath(std::string_view(argv[0]), std::string_view(argv[1]));
    result.out_path = NormalizePath(std::string_view(argv[0]), std::string_view(argv[2]));

    std::string buff;
    FilterDescription fd;
    // реализовать парсинг фильтров
    for (int i = 3; i < argc; ++i) {
        int length = strlen(argv[i]);
        if (argv[i][0] == '-') {
            for (int j = 1; j < length; ++j) {
                buff.push_back(argv[i][j]);
            }
            fd.name = buff;
            buff.clear();
            if (i < argc - 1) {
                if (argv[i + 1][0] == '-') {
                    result.filter_descriptions.push_back(fd);
                    fd.Clear();
                }
            } else {
                result.filter_descriptions.push_back(fd);
                fd.Clear();
            }

        } else {
            for (int j = 0; j < length; ++j) {
                buff.push_back(argv[i][j]);
            }
            fd.parameters.push_back(buff);
            buff.clear();
            if (i < argc - 1) {
                if (argv[i + 1][0] == '-') {
                    result.filter_descriptions.push_back(fd);
                    fd.Clear();
                }
            } else {
                result.filter_descriptions.push_back(fd);
                fd.Clear();
            }
        }
    }
    return result;

}

std::shared_ptr<Filter> GetPtr(FilterDescription filter_description) {
    if (filter_description.name == "crop") {
        if (filter_description.parameters.size() == 2) {
            try {
                std::stoi(filter_description.parameters[0]);
                std::stoi(filter_description.parameters[1]);
            } catch (std::invalid_argument& e) {
                throw std::runtime_error("parameters for -crop must be integers");
            }
            if (stoi(filter_description.parameters[0]) >= 0 && stoi(filter_description.parameters[1]) >= 0) {
                std::shared_ptr<Crop> p (new Crop(stoi(filter_description.parameters[0]), stoi(filter_description.parameters[1])));
                return p;
            } else {
                throw std::runtime_error("parameters for crop must greater than 0");
            }
        } else {
            throw std::runtime_error("invalid number of parameters for -crop (there must be 2)");
        }
    } else if (filter_description.name == "gs") {
        std::shared_ptr<GreyScale> p (new GreyScale);
        return p;
    } else if (filter_description.name == "neg") {
        std::shared_ptr<Negative> p (new Negative);
        return p;
    } else if (filter_description.name == "sharp") {
        std::shared_ptr<Sharp> p (new Sharp);
        return p;
    } else if (filter_description.name == "edge") {
        if (filter_description.parameters.size() == 1) {
            try {
                std::stof(filter_description.parameters[0]);
            } catch (std::invalid_argument& e) {
                throw std::runtime_error("parameter for -edge must be float");
            }
            if (std::stof(filter_description.parameters[0]) >= 0 && std::stof(filter_description.parameters[0]) <= 1) {
                std::shared_ptr<Edge> p (new Edge(stof(filter_description.parameters[0])));
                return p;
            } else {
                throw std::runtime_error("parameter for -edge must be float from 0 to 1");
            }
        } else {
            throw std::runtime_error("invalid number of parameters for -crop (there must be 1)");
        }
    } else if (filter_description.name == "blur") {
        if (filter_description.parameters.size() == 1) {
            try {
                std::stof(filter_description.parameters[0]);
            } catch (std::invalid_argument& e) {
                throw std::runtime_error("parameter for -blur must be float");
            }
            std::shared_ptr<Blur> p (new Blur(stof(filter_description.parameters[0])));
            return p;
        } else {
            throw std::runtime_error("invalid number of parameters for -crop (there must be 1)");
        }
    } else {
        throw std::runtime_error("Invalid input. Please, check your parameters and file names.");
    }
}
