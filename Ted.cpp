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
    FileOperations fileOperations;
    fileOperations.printToScreen(fileName);
    std::string addToFile;
    do {
        std::ofstream out;
        out.open(fileName, std::ios::app);
        getline(std::cin, addToFile);
        if (addToFile == ":q") {
            out.close();
            exit(0);
        }
        if (addToFile == ":r") {
            fileOperations.replace(fileName);
            // TODO check on windows
            system("clear");
            fileOperations.printToScreen(fileName);
        } else if (addToFile == ":d") {
            fileOperations.deleteLine(fileName);
            // TODO check on windows
            system("clear");
            fileOperations.printToScreen(fileName);
        } else {
            out << std::endl << addToFile;
        }
        out.close();
//        fileOperations.printToScreen(fileName);
    } while (addToFile != ":q");
    return 0;
}
