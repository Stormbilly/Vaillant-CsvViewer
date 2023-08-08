#include <gmock/gmock.h>
#include "CSVLoader.h"

namespace csv
{
	namespace domain
	{
		using namespace testing;

		bool compare2DVectors (std::vector <std::vector <std::string> >& A, std::vector <std::vector <std::string> >& B)
		{
			if (A.size() != B.size())
			{
				return false;
			}

			for (int i = 0; i < A.size(); ++i)
			{
				if (A [i].size() != B [i].size())
				{
					return false;
				}

				for (int j = 0; j < A[i].size(); ++j)
				{
					if (A[i][j] != B[i][j])
					{
						return false;
					}
				}
			}

			return true;
		}

		TEST(CSVLoader, empty)
		{
			// Arrange
			std::vector <std::vector <std::string> > expected;

			// Act
			std::vector <std::vector <std::string> > result = loadCSVFromString ("");

			// Assert
			EXPECT_EQ (expected.size(), result.size());
		}

		TEST(CSVLoader, Simple)
		{
			// Arrange
			std::vector <std::vector <std::string> > expected = {{"one", "two"}, {"three", "four"}};

			// Act
			std::vector <std::vector <std::string> > result = loadCSVFromString ("one:two\nthree:four");

			// Assert
			EXPECT_EQ (expected.size(), result.size());
		}
	}
}