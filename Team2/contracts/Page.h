#pragma once
#include <string>
#include <vector>

namespace csv
{
	namespace contracts
	{
		struct Page
		{
			std::vector<std::string> Header;
			std::vector<std::vector<std::string>> Rows;
		};
	}
}