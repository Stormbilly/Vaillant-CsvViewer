#include <fstream>

#include "FileLoader.h"

std::string loadFile (const std::string path, csv::contracts::GlobalErrors& outErr)
{
    std::ifstream ifs(path.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

    if (ifs.good())
    {
        std::ifstream::pos_type fileSize = ifs.tellg();
        ifs.seekg(0, std::ios::beg);

        std::vector<char> bytes(fileSize);
        ifs.read(bytes.data(), fileSize);

        return std::string(bytes.data(), fileSize);
    }
    else
    {
        outErr = FileNotFound;
    }

    
}