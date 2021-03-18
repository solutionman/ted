//
// Created by dima on 3/18/21.
//

#include <iostream>
#include "Help.h"

void Help::getHelp(int argc, char **argv, std::string &fileName) {
    if (argc == 1 || (fileName == "-h" || fileName == "--h" || fileName == "-help" || fileName == "--help") ) {
        std::cout << "usage: "
                     "enter the name of file" << std::endl;
        std::exit(0);
    }
}

