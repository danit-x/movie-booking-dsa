#ifndef CONSOLEIO_H
#define CONSOLEIO_H

class ConsoleIO
{
public:
    static void printDivider();
    static void pause();

    static int readInt(const char *prompt, int minVal, int maxVal);
    static void readLine(const char *prompt, char *out, int maxLen);
};

#endif