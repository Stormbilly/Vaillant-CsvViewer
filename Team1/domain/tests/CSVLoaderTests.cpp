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

		TEST(CSVLoader, emptyString)
		{
			// Act
			std::vector <std::vector <std::string> > result = parseCSV ("");

			// Assert
			std::vector <std::vector <std::string> > expected;
			EXPECT_EQ (expected.size(), result.size());
			EXPECT_EQ (expected, result);
		}

		TEST(CSVLoader, Simple2and2Matrix)
		{
			// Act
			std::vector <std::vector <std::string> > result = parseCSV ("one;two\nthree;four");

			// Assert
			std::vector <std::vector <std::string> > expected = {{"one", "two"}, {"three", "four"}};
			compare2DVectors (expected, result);
			EXPECT_EQ (expected, result);
		}
	}
}