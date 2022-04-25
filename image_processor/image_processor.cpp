#include "lib/parser/parser.h"


#include <iostream>


int main(int argc, const char * argv[]) {
    if (argc > 1) {
        ArgParser prs;
        ParseResults input = prs.Parse(argc, argv);
        for (auto it : input.filter_descriptions) {
            GetPtr(it)->Apply(input.in_path, input.out_path);
            if (input.in_path != input.out_path) {
                input.in_path = input.out_path;
            }
        }
        return 0;
    } else {
        std::cout << "Input format: {program name} {input file path} {output file path} [-{filter 1 name} [1st parameter of filter 1]"
                     " [2nd parameter of filter 1] ...] [-{filter 2 name} [1st parameter of filter 2]"
                     " [2nd parameter of filter 2] ...] ..." << std::endl << "Filters:" << std::endl << "-crop [int] [int]  -  crops image from top left corner to assigned size (in pixels)"
                    << std::endl << "-edge [0 < float < 1]  -  highlights edges on the image" << std::endl << "-gs  -  turns image to black-and-white" << std::endl <<
                    "-neg  -  turns image to negative colors"  << std::endl << "-sharp  -  sharpens image" << std::endl << "-blur [float]  -  blurs the image";
    }
 }
