//
// Created by akhanov on 11/28/2015.
//

#include "InterfaceTerminalConsole.h"
#include <iostream>
#include <string>
#include <cstring>

InterfaceTerminalConsole::InterfaceTerminalConsole() {
}

int InterfaceTerminalConsole::read(std::string &buffer) {
    std::cin >> buffer;
    return buffer.size();
}

int InterfaceTerminalConsole::read(char *buffer) {
    return 0;
}

int InterfaceTerminalConsole::write(std::string &buffer) {
    std::cout << buffer;
    return buffer.size();
}

int InterfaceTerminalConsole::write(const char *buffer) {
    std::cout << buffer;
    return strlen(buffer);
}
