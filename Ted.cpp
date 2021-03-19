#include <iostream>
#include <fstream>
#include "Help.h"
#include "FileOperations.h"

int main(int argc, char **argv) {
    std::string fileName;
    if(argc > 1){
        fileName = argv[1];
    }
    Help::getHelp(argc, argv, fileName);
    std::ofstream file(fileName);
    FileOperations fileOperations;
    fileOperations.printToScreen(fileName);
    fileOperations.writeToFile(fileName);
    return 0;
}
