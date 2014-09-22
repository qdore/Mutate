#include <fstream>
#include <iostream>
#include <sstream>
#include <QDir>
#include <QDirIterator>
#include <QProcess>
#include <sstream>
#include "config_parse.h"

using namespace std;

ConfigParse::ConfigParse (const char *file)
{
    parse (file);
}

ConfigParse::ConfigParse (const string &file)
{
    parse (file.c_str());
}

ConfigParse::iterator ConfigParse::begin (const string &section)
{
    unordered_map<string, unordered_map<string, string> >::iterator it;
    it = config.find (section);

    if (it != config.end())
    {
        return (it->second.begin());
    }
    else
    {
        throw ConfigParseEx ("Section \"" + section + "\" does not exist");
    }
}

ConfigParse::iterator ConfigParse::end (const string &section)
{
    unordered_map<string, unordered_map<string, string> >::iterator it;
    it = config.find (section);

    if (it != config.end())
    {
        return (it->second.end());
    }
    else
    {
        throw ConfigParseEx ("Section \"" + section + "\" does not exist");
    }
}


string ConfigParse::getValue (const string &section, const string &name)
{
    unordered_map<string, unordered_map<string, string> >::iterator it;
    unordered_map<string, string>::iterator section_it;

    it = config.find (section);
    if (it != config.end())
    {
        section_it = it->second.find (name);
        if (section_it == it->second.end())
        {
            return (string());
        }
        else
        {
            return (section_it->second);
        }
    }
    else
    {
        return (string());
    }

}

void ConfigParse::parse (const char *file)
{
    unsigned int line_number = 0;
    string line;
    ifstream f (file);

    if (!f.is_open())
    {
        throw ConfigParseEx ("Cannot open ini file");
        return;
    }
    pair<unordered_map<string, unordered_map<string, string> >::iterator, bool> inserted;
    inserted.second = false;
    while (getline (f, line))
    {
        ++line_number;
        if (!line.size() || line[0] == ';' || line[0] == '#' || line[0] == ' ')
        {
            continue;
        }

        if (line[0] == '[')
        {
            size_t pos = line.find (']');
            if (pos == string::npos)
            {
                f.close();
                throw ConfigParseEx ("INI parse failed - improperly defined section heading", line_number);
                return;
            }
            string section (line, 1, pos - 1);

            //check if section exists
            unordered_map<string, unordered_map<string, string> >::iterator it;
            it = config.find (section);
            if (it != config.end())
            {
                f.close();
                throw ConfigParseEx ("INI parse failed - duplicate section names", line_number);
                return;
            }

            inserted = config.insert (make_pair (section, unordered_map<string, string>()));

            if (!inserted.second)
            {
                f.close();
                throw ConfigParseEx ("Unordered map insertion failed");
                return;
            }
        }
        else
        {
            if (inserted.second)
            {
                string name, value;
                size_t pos = line.find ('=');
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
                if (pos == string::npos)
                {
                    f.close();
                    throw ConfigParseEx ("INI parse failed - improperly formed name/value pair", line_number);
                    return;
                }
                name = string (line, 0, pos);
                value = string (line, pos + 1, line.size() - 1);

                inserted.first->second.insert (make_pair (name, value));
            }
        }
    }
    f.close();
}
vector<string> ConfigParse::getSections() const
{
    vector<string> sections;
    unordered_map<string, section>::const_iterator it;

    it = config.begin();

    while (it != config.end())
    {
        sections.push_back (it->first);
        ++it;
    }

    return (sections);
}

ConfigParseEx::ConfigParseEx (const char* m) : msg (m) {}
ConfigParseEx::ConfigParseEx (const std::string& m) : msg (m) {}
ConfigParseEx::ConfigParseEx (const char* m, const unsigned int l)
{
    msg = m;
    msg += " on line " + std::to_string (l);
}

ConfigParseEx::ConfigParseEx (const std::string& m, const unsigned int l)
{
    msg = m;
    msg += " on line " + std::to_string (l);
}

const char* ConfigParseEx::what() const throw()
{
    return (msg.c_str());
}
