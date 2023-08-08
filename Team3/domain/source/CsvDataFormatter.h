#pragma once

#include "CsvDataStream.h"
#include "DataTable.h"
#include "DisplayedData.h"


namespace csv
{
    class CsvDataFormatter
    {
        public:

             static contracts::DisplayedData getDisplayedContent(contracts::DataTable inputDataTable, int pageSize);

    };
}