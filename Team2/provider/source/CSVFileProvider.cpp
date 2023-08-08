#include "CSVFileProvider.h"
#include <fstream>
#include <vector> 


namespace csv
{   
    std::vector<std::string> CSVFileProvider::ReadCSVFile(const std::string& file_path)
    {
        auto csv_file = std::ifstream{};
        auto csv_lines = std::vector<std::string> {};


        csv_file.open(file_path);
        if (csv_file.is_open())
        {
            for (std::string line; std::getline(csv_file, line); ){
                csv_lines.push_back(line);
            }              
        }
        else
        {
          csv_lines.push_back("File Error");  
        }
        csv_file.close();   
               
        return csv_lines;
    }

} // namespace csv