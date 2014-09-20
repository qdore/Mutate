#ifndef __CONFIG_PARSE__
#define __CONFIG_PARSE__

#include <string>
#include <unordered_map>
#include <exception>
#include <vector>
#include <sstream>

class ConfigParse
{

    typedef std::unordered_map<std::string, std::string> section;

public:
    ConfigParse (const char *file);
    ConfigParse (const std::string &file);

    typedef section::iterator iterator;
    typedef section::const_iterator const_iterator;

    iterator begin (const std::string &section);
    iterator end (const std::string &section);
    std::string getValue (const std::string &section, const std::string &name);
    std::vector<std::string> getSections() const;
    void storeValue(std::string file);

private:
    void parse (const char *file);
    void parse (std::istringstream &str);

    std::unordered_map<std::string, section> config;
};


class ConfigParseEx : public std::exception
{
public:

    ConfigParseEx (const char* m);
    ConfigParseEx (const std::string& m);
    ConfigParseEx (const char* m, const unsigned int l);
    ConfigParseEx (const std::string& m, const unsigned int l);


    virtual const char* what() const throw();

    std::string msg;
};

#endif
