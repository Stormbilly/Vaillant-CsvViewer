#pragma once
#include <tuple>
#include "Page.h"

namespace csv
{
    class Interactor
    {
    public:
        static contracts::Page Start(const char** argv, unsigned int argc);
    };

}
