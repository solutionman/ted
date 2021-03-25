#include <fstream>
#include "FileOperations.h"
#include <cstdio>
#include <cstring>

void FileOperations::printToScreen(const std::string &fileName) {
    std::string text;
    std::ifstream file(fileName);
    while (getline(file, text)) {
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
        if (addToFile != ":q") {
            out << std::endl << addToFile;
        }
    } while (addToFile != ":q");
}

void FileOperations::deleteLine(const std::string &fileName) {
    std::cout << "Print line to delete" << std::endl;
    std::string searchLine;
    getline(std::cin, searchLine);
    std::string lineInFile;
    std::ifstream currentFile(fileName);
    std::ofstream tempFile("tempFile.txt");
    bool first = true;
    while (getline(currentFile, lineInFile)) {
        if (lineInFile != searchLine) {
            if (first) {
                tempFile << lineInFile;
            } else {
                tempFile << std::endl << lineInFile;
            }
            first = false;
        }
    }
    currentFile.close();
    tempFile.close();
    char origName[fileName.length() + 1];
    strcpy(origName, fileName.c_str());
    if (remove(origName) != 0) {
        std::cout << "error in removing file " << origName << std::endl;
    }
    if (rename("tempFile.txt", origName) != 0) {
        std::cout << "error in deleting in file" << std::endl;
    }
}

void FileOperations::replace(const std::string &fileName) {
    std::cout << "Print line to replace" << std::endl;
    std::string searchLine;
    getline(std::cin, searchLine);
    std::cout << "Print what to write instead" << std::endl;
    std::string replacement;
    getline(std::cin, replacement);

    std::string myText;
    std::ifstream currentFile(fileName);
    std::ofstream temporaryFile("tempFile.txt");
    bool first = true;
    while (getline(currentFile, myText)) {
        if (myText == searchLine) {
            if (first) {
                temporaryFile << replacement;
            } else {
                temporaryFile << std::endl << replacement;
            }
        } else {
            if (first) {
                temporaryFile << myText;
            } else {
                temporaryFile << std::endl << myText;
            }
        }
        first = false;
    }
    currentFile.close();
    temporaryFile.close();
    int length = fileName.length();
    char origName[length + 1];
    strcpy(origName, fileName.c_str());
    if(remove(origName) != 0){
        std::cout << "error in removing file " << origName << std::endl;
    }
    if (rename("tempFile.txt", origName) != 0) {
        std::cout << "error in renaming tempFile.txt" << std::endl;
    }
}