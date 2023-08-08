#pragma once

#include "CsvDataStream.h"
#include "DataTable.h"
#include "DisplayedData.h"


namespace csv
{
    class CsvDataParser
    {
        public:

             static contracts::DataTable parseFile(contracts::CsvDataStream inputDataStream);

    };
}