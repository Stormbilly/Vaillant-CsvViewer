#include "CSVLoader.h"

#include <sstream>

std::vector <std::vector <std::string> > loadCSVFromString (const std::string& entireFile)
{
    std::vector <std::vector <std::string> > result;

    std::vector<std::string> lines;
 
    std::stringstream ss(entireFile);
    std::string token;
    while (std::getline(ss, token, '\n')) {
        lines.push_back(token);
    }

    for (auto line :lines)
    {
        result.push_back (std::vector <std::string> ());

        std::stringstream s2(line);
        while (std::getline(ss, token, '\n')) {
            result.back().push_back(token);
        }
    }
 
    return result;
}