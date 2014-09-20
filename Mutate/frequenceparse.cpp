#include "frequenceparse.h"
#include <fstream>
#include <iostream>

using namespace std;

FrequenceParse::FrequenceParse(const char *file)
{
    this->file = file;
    ifstream in(file);
    while (in)
    {
        int tmp;
        string stmp;
        in >> stmp;
        if (!in) break;
        in >> tmp;
        parse.insert({stmp, tmp});
    }
    in.close();
}
int FrequenceParse::getValue(string str) const
{
    auto k = parse.find(str);
    if (k != parse.end())
    {
        return (*k).second;
    }
    else {
        return 0;
    }
}

void FrequenceParse::addValue(string str, int val)
{
    auto k = parse.find(str);
    if (k != parse.end())
    {
        (*k).second += val;
    }
    else {
        parse.insert({str, val});
    }
}

int FrequenceParse::getValue(returnByScript val) const
{
    return this->getValue(val.icon);
}

void FrequenceParse::storeValue()
{
    ofstream out(file.c_str());
    for (auto x: parse)
    {
        out << x.first << ' ' << x.second << endl;
    }
    out.close();
}
