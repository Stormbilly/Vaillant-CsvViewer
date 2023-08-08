#include <gmock/gmock.h>
#include "Domain.h"
#include "Page.h"

namespace csv
{
	namespace domain
	{
		using namespace testing;

		TEST(DomainTests, hey)
		{
			Domain domain;
		}

		TEST(DomainTests, Page_Constructor_EmptyCsv)
		{
			std::vector <std::vector <std::string> > csv;

			contracts::Page dummy_page(csv, 42);

			EXPECT_THAT(dummy_page.header.size(), 0);
			EXPECT_THAT(dummy_page.values.size(), 0);
			EXPECT_THAT(dummy_page.firstLine, 0);
			EXPECT_THAT(dummy_page.numberOfRows, 42);
		}

		TEST(DomainTests, Page_Constructor_InvalidNumberOfRows)
		{
			std::vector <std::vector <std::string> > csv = {{"header1", "header2"}};

			contracts::Page dummy_page(csv, 42);

			EXPECT_THAT(dummy_page.header.size(), 0);
			EXPECT_THAT(dummy_page.values.size(), 0);
			EXPECT_THAT(dummy_page.firstLine, 0);
			EXPECT_THAT(dummy_page.numberOfRows, 42);
		}

		TEST(DomainTests, Page_Constructor_ValidNumberOfRows)
		{
			std::vector <std::vector <std::string> > csv = {{"header1", "header2"}, {"value1", "value2"}};

			contracts::Page dummy_page(csv, 24);

			EXPECT_THAT(dummy_page.header.size(), 1);
			EXPECT_THAT(dummy_page.values.size(), 1);
			EXPECT_THAT(dummy_page.firstLine, 0);
			EXPECT_THAT(dummy_page.numberOfRows, 24);
		}
	}
}