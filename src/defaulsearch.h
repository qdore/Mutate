#ifndef DEFAULSEARCH_H
#define DEFAULSEARCH_H

#include "returnbyscript.h"
#include <regex>
#include <string>
#include <vector>
#include <map>
#include <QIcon>

typedef std::vector<std::pair<std::string, std::pair<std::string, QIcon*>>> pair;

class defaulSearch
{
    std::string keyword;
    std::vector<returnByScript> vals;
public:
    defaulSearch(std::string keyword);
    std::vector<returnByScript> getReturnVec(const pair& map);
    void searchApps(const pair& map, bool& changeCalc);
    void searchScripts();
    void netSearch(bool& searchApp);
    void calcSearch(bool& changeCalc);
    bool noScriptMatches();
};

#endif // DEFAULSEARCH_H
