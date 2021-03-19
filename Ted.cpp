#include <iostream>
#include "Help.h"

int main(int argc, char **argv) {
    std::string fileName;
    if(argc > 1){
        fileName = argv[1];
    }
    Help::getHelp(argc, argv, fileName);
    

    return 0;
}
