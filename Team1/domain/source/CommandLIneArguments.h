#include <string>

namespace csv
{
	namespace domain
	{
        struct Arguments {
            std::string filePath;
            unsigned int noOfRows;
        };
        
        Arguments parseArgs (const char** argv, int argc);
    };
};
