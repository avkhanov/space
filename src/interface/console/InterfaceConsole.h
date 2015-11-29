//
// Created by akhanov on 11/27/2015.
//

#ifndef SPACE_INTERFACECONSOLEABSTRACT_H
#define SPACE_INTERFACECONSOLEABSTRACT_H

#include <string>


class InterfaceConsole {
public:
    virtual int write(std::string &buffer) = 0;
    virtual int write(const char *buffer) = 0;

    virtual int read(std::string &buffer) = 0;
    virtual int read(char *buffer) = 0;
};


#endif //SPACE_INTERFACECONSOLEABSTRACT_H
