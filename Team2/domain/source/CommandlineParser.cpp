#include "CommandlineParser.h"
#include <string>
#include <stdexcept>
namespace csv
{    
    std::tuple<std::string, int> CommandlineParser::ParseCommandline(char **argv, int argc)
    {
        if(argc <= 1)
        {
            throw std::out_of_range("File is missing");
        }
        else if(argc == 2)
        {
            return std::tuple<std::string, int>(std::string(argv[1]), 3);
        }
        else
        {
            int page_size;
            try
            {
               page_size = std::stoi(argv[2]);
            }
            catch(const std::exception& e)
            {
                throw std::invalid_argument("Page size not convertable");
            }

            if (page_size < 1)
            {
                throw std::out_of_range("Number of pages to small");
            }
            return std::tuple<std::string, int>(std::string(argv[1]), page_size);
        }
    }

} // namespace csv