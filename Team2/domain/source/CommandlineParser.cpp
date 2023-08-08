#include "CommandlineParser.h"

namespace csv
{
    std::tuple<std::string, int> CommandlineParser::ParseCommandline(char **argv, int argc)
    {
        if(argc <= 1)
        {
            return std::tuple<std::string, int>();
        }
        else if(argc == 2)
        {
            return std::tuple<std::string, int>(std::string(argv[1]), 3);
        }
        else if( argc >= 3)
        {
            return std::tuple<std::string, int>(std::string(argv[1]), atoi(argv[2]));
        }
        else
        {
            return std::tuple<std::string, int>();
        }
            
    }

} // namespace csv