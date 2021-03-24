#include <iostream>

#ifndef TED_FILEOPERATIONS_H
#define TED_FILEOPERATIONS_H

class FileOperations {
public:
    void printToScreen(const std::string &fileName);
    void writeToFile(const std::string &fileName);
    void deleteLine(const std::string &fileName);
};


#endif //TED_FILEOPERATIONS_H
