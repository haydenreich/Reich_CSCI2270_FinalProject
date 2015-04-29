#include <string>
#include <iostream>
#include <vector>
#ifndef UTILITIES_H
#define UTILITIES_H

class Utilities
{
    public:
    Utilities();
    ~Utilities();
    void readFile(std::string fileName);
    std::vector<std::string> getWords();
    void clearWords();
    protected:
    private:
    std::vector<std::string> words;
};

#endif // UTILITIES_H
