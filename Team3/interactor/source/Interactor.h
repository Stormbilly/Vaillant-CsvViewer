#pragma once
#include <string>
#include "DisplayedData.h"

namespace csv
{
    class Interactor
    {
    public:
        static contracts::DisplayedData Start(std::vector<std::string> cmdLine);
    };

}