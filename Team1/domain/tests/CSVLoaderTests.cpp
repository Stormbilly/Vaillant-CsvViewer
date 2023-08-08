#include <gmock/gmock.h>
#include "CSVLoader.h"

namespace csv
{
	namespace domain
	{
		using namespace testing;

		void compare2DVectors (std::vector <std::vector <std::string> >& A, std::vector <std::vector <std::string> >& B)
		{
			if (A.size() != B.size())
			{
				ASSERT_EQ (A.size(), B.size());
			}

			for (int i = 0; i < A.size(); ++i)
			{
				ASSERT_EQ (A [i].size(), B [i].size());

				for (int j = 0; j < A[i].size(); ++j)
				{
					ASSERT_EQ (A[i][j],B[i][j]);
				}
			}
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
			std::vector <std::vector <std::string> > result = loadCSVFromString ("one;two\nthree;four");

			// Assert
			compare2DVectors (expected, result);
		}
	}
}