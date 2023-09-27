#include <gmock/gmock.h>
#include "../source/Ui.h"
#include "../../contracts/Page.h"

namespace csv
{
	contracts::Page CreatePage() {
		contracts::Page page;
		page.header = {"Header 1", "H2" , "head4"};
		std::vector<std::string> value =  {"Test 1","2", "three"};
		page.values.push_back(value);
		value =  {"This is a test","", "Hello"};
		page.values.push_back(value);
		return page;
	}

	using namespace testing;
	
	TEST(Ui, ComputeLengthOfCells)
	{
		UI ui;
		contracts::Page page = CreatePage();
		std::vector<uint16_t> length = ui.ComputeLengthOfCells(page);
		EXPECT_EQ (length.size(), 3);
		EXPECT_EQ (length[0], 14);
		EXPECT_EQ (length[1], 2);
		EXPECT_EQ (length[2], 5);
	}

	TEST(Ui, BuildOutputLine)
	{
		UI ui;
		contracts::Page page = CreatePage();
		std::vector<uint16_t> length = ui.ComputeLengthOfCells(page);

		std::string line = ui.BuildOutputLine(page.header, length);
		EXPECT_EQ (line , "      Header 1|H2|head4|\n");
		line = ui.BuildOutputLine(page.values[0], length);
		EXPECT_EQ (line , "        Test 1| 2|three|\n");
		line = ui.BuildOutputLine(page.values[1], length);
		EXPECT_EQ (line , "This is a test|  |Hello|\n");
	}
}