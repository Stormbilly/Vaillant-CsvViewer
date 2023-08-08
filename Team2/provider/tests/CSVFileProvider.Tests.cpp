#include <gmock/gmock.h>
#include <string>
#include <vector>

#include "CSVFileProvider.h"


namespace csv
{
	using namespace testing;
	
	TEST(CSVFileProviderTests, ReadCSV_ValidFile_CorrectLine)
	{

		auto testpath = std::string{"./testfile.csv"};
		auto actual = CSVFileProvider::ReadCSVFile(testpath);
		const std::vector<std::string> expected = {"Name;Age;City"   
												   "Peter;42;New York"};
		EXPECT_EQ(actual, expected);				
	}
}