#include <gmock/gmock.h>
#include "FileLoader.h"

namespace csv
{
	namespace domain
	{
		using namespace testing;

		TEST(FileLoaderTest, goodCase)
		{
			//Act
			std::string result = loadFile ("testInput.csv");

			// Assert
			std::string expected = "one; two; three-\nfour\n";
			EXPECT_EQ (expected, result);
		}
	}
}