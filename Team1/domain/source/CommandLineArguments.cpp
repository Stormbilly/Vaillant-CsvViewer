#include "CommandLIneArguments.h"

namespace csv
{
	namespace domain
	{

        Arguments parseArgs (const char** argv, const int argc)
        {
            Arguments arguments;
            std::size_t pos;
            arguments.filePath = argv[1];
            arguments.noOfRows = std::stoi(argv[2], &pos);

            return arguments;
        }
    }
}