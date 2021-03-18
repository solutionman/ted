#ifndef TED_HELP_H
#define TED_HELP_H

#include <string>

class Help {
public:
    static void getHelp(int argc, char **argv, std::string &fileName);
};

#endif //TED_HELP_H
