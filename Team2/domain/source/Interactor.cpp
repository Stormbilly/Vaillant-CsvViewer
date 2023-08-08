#include "Interactor.h"
#include "CommandlineParser.h"
#include "CSVFileProvider.h"
#include "CSVFileParser.h"
#include "PageProvider.h"

namespace csv
{
    contracts::Page Interactor::Start(char **argv, int argc)
    {
        CommandlineParser command_line;
        CSVFileProvider csv_file_provider;
        CSVFileParser csv_file_parser;
        PageProvider page_provider;
        
        auto [filename, page_size] = command_line.ParseCommandline(argv, argc);
        auto csv_file = csv_file_provider.ReadCSVFile(filename);
        auto page = csv_file_parser.ParseCSV(csv_file);
        auto page_to_display = page_provider.ProvidePage(page, page_number, page_size);

        return page_to_display;
    }


} // namespace csv
