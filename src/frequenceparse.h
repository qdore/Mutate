#ifndef FREQUENCEPARSE_H
#define FREQUENCEPARSE_H
#include <unordered_map>
#include <string>
#include <returnbyscript.h>

class FrequenceParse
{
    std::unordered_map<std::string, int> parse;
    std::string file;
public:
    FrequenceParse(const char* file);
    int getValue(std::string str) const;
    int getValue(returnByScript val) const;
    void addValue(std::string str, int val);
    void storeValue();
};

#endif // FREQUENCEPARSE_H
