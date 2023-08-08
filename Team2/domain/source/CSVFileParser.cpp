#include "CSVFileParser.h"

namespace csv
{
    contracts::Page CSVFileParser::ParseCSV(const std::vector<std::string>& csv_file_data)
    {
        auto page = contracts::Page{};
        int header_column = 0;

        for (auto it = csv_file_data[0].begin(); it != csv_file_data[0].end(); it ++)
        {
            if (*it == ';'){
                header_column ++;
            }
            else if(*it == '/n'){
                break;
            }
            else{
                page.Header[header_column] += *it;

            }
        }

        // for (auto it = csv_file_data[1].begin() ;  csv_file_data) {

        // }

        return page;
    }

} // namespace csv