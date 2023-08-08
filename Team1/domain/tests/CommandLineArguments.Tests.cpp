#include <gmock/gmock.h>
#include "CommandLIneArguments.h"

namespace csv
{
	namespace domain
	{
		using namespace testing;

		TEST(CommandLineArgumentsTests, hey)
		{
            /*
            std::vector<char*> argv;
            argv.push_back((char*)"CSV.csv");
            argv.push_back((char*)"40");
            argv.push_back(nullptr);
            */
            char* args[] = {(char*)"CSV.csv", (char*)"40", NULL};
	        
            Arguments arguments = parseArgs(args, 2);

            EXPECT_THAT(arguments.noOfRows, 2);
            EXPECT_THAT(arguments.filePath, "CSV.csv");
		}
	}
}
