#pragma once

#include "CsvDataStream.h"

namespace csv
{
    class CsvDataProvider
    {
        public:

            static contracts::CsvDataStream getFile(std::string csvPath);
    };
}