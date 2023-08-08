#pragma once

#include "CsvDataStream.h"

namespace csv
{
    class CsvDataProvider
    {
        public:

            contracts::CsvDataStream getFile(std::string csvPath);
    };
}