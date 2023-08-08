#include "CommandlineParser.h"
#include <string>
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
            try
            {
               int page_size = std::stoi(argv[2]);
               return std::tuple<std::string, int>(std::string(argv[1]), page_size);
            }
            catch(const std::exception& e)
            {
                return std::tuple<std::string, int>(std::string(argv[1]), 3);
            }
        }
        else
        {
            return std::tuple<std::string, int>();
        }
            
    }

} // namespace csv