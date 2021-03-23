#include <iostream>
#include "Help.h"

void Help::getHelp(int argc, char **argv, std::string &fileName) {
    if (argc == 1 || (fileName == "-h" || fileName == "--h" || fileName == "-help" || fileName == "--help")) {
        std::cout << "usage: \n"
                     "enter the name of file\n"
                     "to quit enter :q" << std::endl;
        std::exit(0);
    }
}

