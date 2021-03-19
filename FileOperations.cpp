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
