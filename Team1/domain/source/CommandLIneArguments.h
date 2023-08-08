#include <string>

struct Arguments {
    std::string filePath;
    unsigned int noOfRows;
};

Arguments parseArgs (const char** argv, int argc);