#pragma once
#include <tuple>
#include "Page.h"

namespace csv
{
    class Interactor
    {
    public:
        static contracts::Page Start(const char** argv, unsigned int argc);
        static contracts::Page NextPage(contracts::Page& currentPage);
        static contracts::Page PrevPage(contracts::Page& currentPage);
        static contracts::Page FirstPage(contracts::Page& currentPage);
        static contracts::Page Lastpage(contracts::Page&);
    };

}
