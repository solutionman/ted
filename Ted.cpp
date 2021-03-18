#include <iostream>
#include "Help.h"

int main(int argc, char **argv) {
    std::string fileName;
    Help::getHelp(argc, argv, fileName);
    return 0;
}
