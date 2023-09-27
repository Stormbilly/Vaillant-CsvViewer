#include "PageProvider.h"

namespace csv
{
    contracts::Page PageProvider::ProvidePage(const contracts::Page& csv_data, int page_number, int lines_per_page)
    {
        contracts::Page page;
        int lines_to_append;
        int startindex = (page_number - 1) * lines_per_page; //Correction with -1 to start at location 0

        page.Header = csv_data.Header;

        if(startindex > csv_data.Rows.size() - 1) {
            lines_to_append = 0;
        }
        else if(startindex + (lines_per_page - 1) > csv_data.Rows.size() - 1) {
            lines_to_append = csv_data.Rows.size() - startindex;
        }
        else {
            lines_to_append = lines_per_page;
        }

        for(int i=0; i < lines_to_append; i++)
        {
            page.Rows.push_back(csv_data.Rows[startindex + i]);
        }
        return page;
    }
} // namespace csv
