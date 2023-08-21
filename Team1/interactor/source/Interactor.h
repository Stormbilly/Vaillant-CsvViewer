#pragma once
#include <tuple>
#include "Page.h"

namespace csv
{
    class Interactor
    {
    public:
        static contracts::Page Start(const char** argv, unsigned int argc);
        static contracts::Page NextPage(contracts::Page&);
        static contracts::Page PrevPage(contracts::Page& currentPage);
    };

}
