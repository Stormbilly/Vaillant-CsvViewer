#include "Interactor.h"
#include "CommandLIneArguments.h"
#include "FileLoader.h"
#include "CSVLoader.h"
#include "Domain.h"

#include <algorithm>

namespace csv
{
    contracts::Page Interactor::Start(const char** argv, unsigned int argc)
    {
        domain::Arguments parsedArgs = domain::parseArgs (argv, argc);
        const auto file = loadFile (parsedArgs.filePath);
        const auto values = parseCSV (file);
        return domain::pageGenerator (values, parsedArgs.noOfRows);
    }

    contracts::Page Interactor::PrevPage(contracts::Page& currentPage)
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

    contracts::Page Interactor::NextPage(contracts::Page& page)
    {
        contracts::Page result = page;

        const auto lastPage = std::max ((long long) page.values.size() - (long long) page.numberOfRows, (long long) 0);
        result.firstLine = std::min (page.firstLine + page.numberOfRows, (unsigned int) lastPage);

        return result;
    }

    contracts::Page Interactor::FirstPage(contracts::Page& page)
    {
        contracts::Page result = page;

        result.firstLine = 0;

        return result;
    }

    contracts::Page Interactor::Lastpage(contracts::Page& page) 
    {
        page.firstLine = std::max((long long)(page.values.size() - page.numberOfRows), (long long)0);
        return page;
    }
}
