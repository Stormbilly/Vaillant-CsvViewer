#include "Interactor.h"
#include "CommandLIneArguments.h"
#include "FileLoader.h"
#include "CSVLoader.h"
#include "Domain.h"

namespace csv
{
    contracts::Page Interactor::Start(const char** argv, unsigned int argc)
    {
        domain::Arguments parsedArgs = domain::parseArgs (argv, argc);
        const auto file = loadFile (parsedArgs.filePath);
        const auto values = parseCSV (file);
        return domain::pageGenerator (values, parsedArgs.noOfRows);
    }

    contracts::Page Interactor::PrevPage(contracts::Page currentPage)
    {
        if(((long long int)currentPage.firstLine - (long long int)currentPage.numberOfRows) < 0)
        {
            currentPage.firstLine = 0;
        }
        else
        {
            currentPage.firstLine -= currentPage.numberOfRows;
        }

        return currentPage;
    }
}