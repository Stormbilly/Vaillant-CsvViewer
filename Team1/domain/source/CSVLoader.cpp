#include "CSVLoader.h"

#include <iostream>

static std::vector<std::string> splitString(const std::string& str , const char delim)
{
    std::vector<std::string> tokens;

    if (str != "")
    {
        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        while ((pos = str.find(delim, prev)) != std::string::npos) {
            tokens.push_back(str.substr(prev, pos - prev));
            prev = pos + 1;
        }
        tokens.push_back(str.substr(prev));
    }
    return tokens;
}

std::vector <std::vector <std::string> > loadCSVFromString (const std::string& entireFile)
{
    std::vector <std::vector <std::string> > result;

    std::vector<std::string> lines = splitString (entireFile, '\n');

    for (const auto& line :lines)
    {
        auto tokens = splitString (line, ';');
        if (tokens.size() > 0)
            result.push_back (tokens);

    }
 
    return result;
}