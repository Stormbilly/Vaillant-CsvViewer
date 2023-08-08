#include <gmock/gmock.h>
#include <string>
#include <vector>

#include "CSVFileProvider.h"


namespace csv
{
	using namespace testing;
	
	TEST(CSVFileProviderTests, ReadCSV_ValidFile_CorrectLine)
	{
		auto actual = CSVFileProvider::ReadCSVFile();
		const std::vector<std::string> expected = {"Name;Age;City"   
												   "Peter;42;New York"};
	}
}