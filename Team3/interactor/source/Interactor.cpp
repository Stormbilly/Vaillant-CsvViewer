#include "Interactor.h"
#include "CommandLineParser.h"
#include "CsvDataFormatter.h"
#include "CsvDataParser.h"
#include "CsvDataProvider.h"

namespace csv
{
    contracts::DisplayedData Interactor::Start(std::vector<std::string> cmdLine)
    {
        const auto [filePath, pageSize] = CommandLineParser::parseCmdLine(cmdLine);
        const auto dataStream = CsvDataProvider::getFile(filePath);
        const auto dataTable = CsvDataParser::parseFile(dataStream);
        const auto displayedData = CsvDataFormatter::getDisplayedContent(dataTable, pageSize);
        return{displayedData};
    }
}