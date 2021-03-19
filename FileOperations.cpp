#include <fstream>
#include "FileOperations.h"

void FileOperations::printToScreen(const std::string &fileName) {
    std::string text;
    std::ifstream file;
    while(getline(file, text)){
        std::cout << text << std::endl;
    }
    file.close();
}

void FileOperations::writeToFile(const std::string &fileName) {
    std::string addToFile;
    do {
        std::ofstream out;
        out.open(fileName, std::ios::app);
        getline(std::cin, addToFile);
        if(addToFile != ":q"){
            out << std::endl << addToFile;
        }
    } while (addToFile != ":q");
}
