#ifndef CONSOLEIO_H
#define CONSOLEIO_H

#include <string>

class ConsoleIO
{
public:
    static int readInt(const std::string &prompt, int minValue, int maxValue);
    static std::string readLine(const std::string &prompt);
    static std::string readName(const std::string &prompt);
    static void printDivider();
    static void pause();
};

#endif
