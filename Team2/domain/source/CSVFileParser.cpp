#include "CSVFileParser.h"

namespace csv
{
    const std::string delimiter = ";";

    std::vector<std::string> splitLine(std::string line) {
        std::vector<std::string> vec;
        size_t pos_start = 0;
        size_t pos_end = 0;

        while ((pos_end = line.find(delimiter, pos_start)) != std::string::npos) {
            vec.push_back(line.substr(pos_start, pos_end - pos_start));
            pos_start = pos_end + 1; //Ignore found delimiter
        }
        //Don´t forget last element
        vec.push_back(line.substr(pos_start, line.size() - pos_start));
        return vec;
    }

    contracts::Page CSVFileParser::ParseCSV(const std::vector<std::string>& csv_file_data)
    {
        contracts::Page parsedCSV;

        parsedCSV.Header = splitLine(csv_file_data[0]);
        for(int i=1; i<csv_file_data.size(); i++) {
            parsedCSV.Rows.push_back(splitLine(csv_file_data[i]));
        }

        return parsedCSV;
    }
} // namespace csv
