#pragma once
#include <tuple>
#include <string>
#include <vector>

namespace csv
{
    class CommandLineParser
    {
        public:

             static std::tuple <std::string, int> parseCmdLine(std::vector <std::string> cmdLineIput);

    };
}