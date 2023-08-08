#include "CSVFileProvider.h"
#include <fstream>
#include <vector> 
#include <algorithm>


namespace csv
{   
    bool IsEndline (char c){
        switch(c)
        {
        case '\r':
        case '\n':
            return true;
        default:
            return false;
        }
    }

    std::vector<std::string> CSVFileProvider::ReadCSVFile(const std::string& file_path)
    {
        auto csv_file = std::ifstream{};
        auto csv_lines = std::vector<std::string> {};


        csv_file.open(file_path);
        if (csv_file.is_open())
        {
            for (std::string line; std::getline(csv_file, line, '\r'); ){
                line.erase(std::remove_if(line.begin(), line.end(), &IsEndline), line.end());
                csv_lines.push_back(line);
            }              
        }
        else
        {
          csv_lines.push_back("File opening error");  
        }
        csv_file.close();   
               
        return csv_lines;
    }

} // namespace csv