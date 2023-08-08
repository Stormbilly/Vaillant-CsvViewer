#include "Domain.h"
#include "Page.h"
#include <vector>
#include <string>

namespace csv
{
    namespace domain
    {
        static contracts::Page pageGenerator(std::vector <std::vector <std::string> > csv, unsigned int numberOfRows)
        {
            contracts::Page ret;
            ret.firstLine = 0;
            ret.numberOfRows = numberOfRows;

            if(csv.size() >= 2)
            {
                ret.header = csv[0];
                ret.values = csv;
                ret.values.erase(ret.values.begin());
            }

            return ret;
        }
    }
} // namespace csv
