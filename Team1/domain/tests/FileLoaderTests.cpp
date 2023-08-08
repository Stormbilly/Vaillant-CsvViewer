#include <gmock/gmock.h>
#include "FileLoader.h"

namespace csv
{
	namespace domain
	{
		using namespace testing;

		TEST(FileLoaderTestsGood, hey)
		{
			// Assert
			std::string expected = "one; two; three-\nfour\n";

			//Act
			std::string result = loadFile ("testInput.csv");

			// Assert
			EXPECT_EQ (expected, result);
		}
	}
}