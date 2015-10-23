#include "defaulsearch.h"
#include "returnbyscript.h"
#include "config_parse.h"
#include "setting.h"
#include <vector>
#include <QFileInfo>
#include "boost/regex.hpp"
#include <QDir>
#include <QFileIconProvider>
#include <iostream>
#include <algorithm>
#include "boost/algorithm/string.hpp"
#include <QProcess>
#include <sstream>
#include <regex>

defaulSearch::defaulSearch(std::string keyword)
    :keyword(keyword)
{}

void trSpace(std::string& line)
{
    for (int j = line.size() - 1; j != -1; j--)
    {
        if (line[j] == ' ' || line[j] != '\n' || line[j] != '\r')
        {
            continue;
        }
        else {
            line = line.substr(0, j);
            break;
        }
    }
}

std::vector<returnByScript> defaulSearch::getReturnVec(const pair& map)
{
    vals.clear();
    bool searchApp = true;
    bool addCalc = false;
    if (searchApp) netSearch(searchApp);
    if (searchApp && noScriptMatches()) calcSearch(addCalc);
    searchScripts();
    if (searchApp) searchApps(map, addCalc);
    if (vals.empty() && !keyword.empty())
    {
        vals.push_back(returnByScript(
                           SEARCHICON,
                           std::string("Search ") + keyword,
                           std::string("xdg-open \"") + std::string(SEARCHURL) + keyword + "\""
                           ));
    }
    return vals;
}

bool defaulSearch::noScriptMatches()
{
    try {
        ConfigParse cp(CONFPATH.c_str());
        auto sects = cp.getSections();
        for (auto beg = sects.begin(); beg != sects.end(); beg++)
        {
            if (*beg == "default") continue;
            std::string begtmp = *beg;
            if (keyword.substr(0, begtmp.size()) == begtmp && keyword[begtmp.size()] == ' ')
            {
                return false;
            }
        }
    }
    catch (...)
    {}
    return true;
}

void defaulSearch::netSearch(bool& searchApp)
try
{
    boost::regex net1("[\\w\\-_]+(\\.[\\w\\-_]+)+([\\w\\-\\.,@?^=%&amp;:/~\\+#]*[\\w\\-\\@?^=%&amp;/~\\+#])?");
    boost::regex net2("(http|ftp|https)://[\\w\\-_]+(\\.[\\w\\-_]+)+([\\w\\-\\.,@?^=%&amp;:/~\\+#]*[\\w\\-\\@?^=%&amp;/~\\+#])?");
    if (boost::regex_match(keyword, net1))
    {
        vals.push_back(returnByScript(
                           INTERNETICON,
                           std::string("http://") + keyword,
                           std::string("xdg-open \"http://") + keyword + "\"",
                           std::string("Open the typed url")
                           ));
    }
    else {
        if (boost::regex_match(keyword, net2)) {
            vals.push_back(returnByScript(
                               INTERNETICON,
                               keyword,
                               std::string("xdg-open ") + keyword,
                               std::string("Open the typed url")
                               ));
            searchApp = 0;
        }
    }
    if (keyword.size() >= 3) {
        std::shared_ptr<ConfigParse> c(new ConfigParse(URLPATH));
        for (const std::string& x: c->getSections())
        {
            if (x.find(keyword) != std::string::npos)
            {
                vals.push_back(returnByScript(
                                   INTERNETICON,
                                   x,
                                   std::string("xdg-open \"") + x + "\"",
                                   std::string("Open the URL from history")
                                   ));
            }
        }
    }
}
catch (...)
{}

void defaulSearch::calcSearch(bool &changeCalc)
{
    if (keyword.find("...") == std::string::npos) {
        bool has_number = false;
        bool has_operator = false;
        for (auto x: keyword) {
            switch (x) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                case '(':
                case ')':{
                        has_operator = true;
                        break;
                }
            }
            if (x <= '9' && x >= '0') {
                has_number = true;
            }
            if (has_operator && has_number) {
                changeCalc = true;
                keyword = std::string("... ") + keyword;
                return;
            }

        }
    }

}

void defaulSearch::searchScripts()
{
    std::string tmp = keyword;
    boost::to_lower(keyword);
    if (keyword.empty())
    {
        return;
    }
    if (std::string("preference").find(keyword) != std::string::npos ||
        std::string("PREFERENCE").find(keyword) != std::string::npos)
    {
        vals.push_back(returnByScript(
                           SETICON,
                           "Preference",
                           "setting"
                           )
                    );
    }

    if (std::string("quit").find(keyword) != std::string::npos ||
        std::string("QUIT").find(keyword) != std::string::npos)
    {
        vals.push_back(returnByScript(
                           QUITICON,
                           "Quit Mutate",
                           "quit"
                           )
                    );
    }
    try {
        ConfigParse cp(CONFPATH.c_str());
        auto sects = cp.getSections();
        for (auto beg = sects.begin(); beg != sects.end(); beg++)
        {
            if (*beg == "default") continue;
            std::string begtmp = *beg;
            if (keyword.substr(0, begtmp.size()) == begtmp && keyword[begtmp.size()] == ' ')
            {
                if (keyword.size() == begtmp.size() + 1)
                {
                    vals.push_back(returnByScript(
                                cp.getValue(*beg, "IconAddress"),
                                *beg,
                                "miss"
                                )
                           );
                }
                else
                {
                    QProcess* newProcess = new QProcess;
                    QStringList argument;
                    argument.push_back(QString::fromStdString(keyword.substr(begtmp.size() + 1, keyword.size())));
                    newProcess->start(QString::fromStdString(cp.getValue(*beg, "ScriptAddress")),
                                     argument);
                    /* get new process result */
                    while (1)
                    {
                        if (newProcess->waitForFinished())
                        {
                            break;
                        }
                    }
                    QByteArray array = newProcess->readAllStandardOutput();
                    std::cout << newProcess->readAllStandardError().data();
                    std::istringstream in(array.data());
                    while (in) {
                        std::string text, command, icon, subtext;
                        getline(in, text);
                        if (text.find('[') != 0) continue;
                        while (command.find("command=") == std::string::npos) getline(in, command);
                        if (in.peek() == int('i')) getline(in, icon);
                        if (in.peek() == int('s')) getline(in, subtext);
                        trSpace(icon);
                        trSpace(text);
                        trSpace(command);
                        trSpace(subtext);
                        icon = icon.substr(5, icon.size() - 5);
                        subtext = subtext.substr(8, subtext.size() - 8);
                        if (icon.empty()){
                            if (subtext.empty()) {
                                vals.push_back(returnByScript(
                                            cp.getValue(*beg, "IconAddress"),
                                            text.substr(1, text.size() - 2),
                                            command.substr(8, command.size() - 8)
                                            )
                                       );
                            }
                            else {
                                vals.push_back(returnByScript(
                                            cp.getValue(*beg, "IconAddress"),
                                            text.substr(1, text.size() - 2),
                                            command.substr(8, command.size() - 8),
                                            subtext
                                            )
                                       );
                            }
                        }
                        else {
                            if (subtext.empty()) {
                                vals.push_back(returnByScript(
                                            icon,
                                            text.substr(1, text.size() - 2),
                                            command.substr(8, command.size() - 8)
                                            )
                                       );
                            }
                            else {
                                vals.push_back(returnByScript(
                                            icon,
                                            text.substr(1, text.size() - 2),
                                            command.substr(8, command.size() - 8),
                                            subtext
                                            )
                                       );
                            }
                        }
                    }
                }
                if (vals.empty())
                {
                    vals.push_back(returnByScript(
                                cp.getValue(*beg, "IconAddress"),
                                *beg,
                                "miss"
                                )
                           );
                }
                break;
            }
            if (begtmp.find(keyword) == 0)
            {
                if (cp.getValue(*beg, "Argument") == std::string("need"))
                {
                    vals.push_back(returnByScript(
                                       cp.getValue(*beg, "IconAddress"),
                                       *beg,
                                       std::string("complete")
                                       )
                                );
                }
                else
                {
                    vals.push_back(returnByScript(
                                       cp.getValue(*beg, "IconAddress"),
                                       *beg,
                                       cp.getValue(*beg, "ScriptAddress")
                                       )
                                );
                }
            }
        }
    }
    catch (...)
    {}
    keyword = std::move(tmp);
}

void defaulSearch::searchApps(const pair& map, bool &changeCalc)
{
    if (changeCalc) keyword = keyword.substr(4, keyword.size());
    if (keyword.empty()) return;
    auto keyword_bak = keyword;
    for (const auto& x:map)
    {
        auto tmp = x.first;
        auto tmp2 = x.second.first;
        boost::to_upper(tmp2);
        boost::to_upper(tmp);
        boost::to_upper(keyword);
        if (tmp.find(keyword) != std::string::npos || tmp2.find(keyword) != std::string::npos)
        {
            vals.push_back(returnByScript(
                               EXEICON,
                               x.first,
                               x.second.first,
                               x.second.first,
                               x.second.second
                               ));

        }
        keyword = keyword_bak;
    }
}

