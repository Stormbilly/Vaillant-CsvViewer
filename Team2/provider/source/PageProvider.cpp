#include "PageProvider.h"

namespace csv
{
    contracts::Page PageProvider::ProvidePage(const contracts::Page& csv_data, int page_number, int lines_per_page)
    {
        contracts::Page page;
        int startindex = (page_number - 1) * lines_per_page; //Correction with -1 to start at location 0

        page.Header = csv_data.Header;
        for(int i=0; i < lines_per_page; i++)
        {
            page.Rows.push_back(csv_data.Rows[startindex + i]);
        }
        return page;
    }
} // namespace csv