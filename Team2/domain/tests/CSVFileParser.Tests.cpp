#include <gmock/gmock.h>
#include "Interactor.h"
#include "CSVFileParser.h"

namespace csv
{
	using namespace testing;

 	TEST(CSVFileParserTests, ParseValidCSV)
	{
          auto expected_csv = contracts::Page {
                {"Name","Age", "City"},
                {{"Peter","42","New York"},
                 {"Peter","42","New York"}
                }
            };

	} 


}