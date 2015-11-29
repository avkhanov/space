//
// Created by akhanov on 11/28/2015.
//

#ifndef SPACE_INTERFACETERMINALCONSOLE_H
#define SPACE_INTERFACETERMINALCONSOLE_H

#include "InterfaceConsole.h"
#include <string>

class InterfaceTerminalConsole : public InterfaceConsole {
public:
    InterfaceTerminalConsole();

    virtual int write(std::string &buffer);
    virtual int write(const char *buffer);

    virtual int read(std::string &buffer);
    virtual int read(char *buffer);
};


#endif //SPACE_INTERFACETERMINALCONSOLE_H
