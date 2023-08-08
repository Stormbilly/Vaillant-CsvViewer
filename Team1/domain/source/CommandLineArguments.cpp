#include "CommandLIneArguments.h"

namespace csv
{
	namespace domain
	{

        Arguments parseArgs (char** argv, int argc)
        {
            Arguments arguments;
            std::size_t pos;
            arguments.filePath = argv[0];
            arguments.noOfRows = std::stoi(argv[1], &pos);

            return arguments;
        }
    }
}