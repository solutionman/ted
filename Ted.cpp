#include <iostream>
#include <fstream>
#include "Help.h"
#include "FileOperations.h"

int main(int argc, char **argv) {
    std::string fileName;
    if (argc > 1) {
        fileName = argv[1];
    }
    Help::getHelp(argc, argv, fileName);
//    std::ofstream file(fileName);
    FileOperations fileOperations;
    fileOperations.printToScreen(fileName);
    std::string addToFile;
    do {
        std::ofstream out;
        out.open(fileName, std::ios::app);
        getline(std::cin, addToFile);
        if (addToFile == ":d") {
            fileOperations.deleteLine(fileName);
        } else if (addToFile != ":q") {
            out << std::endl << addToFile;
        }
        out.close();
        fileOperations.printToScreen(fileName);
    } while (addToFile != ":q");
//    fileOperations.writeToFile(fileName);
    return 0;
}
