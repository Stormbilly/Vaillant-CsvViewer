#pragma once
#include <string>
#include <vector>
#include <list>

namespace csv
{
	namespace contracts
	{
		struct DisplayedData
		{
			std::vector <std::string> title;
            std::list <std::vector <std::string>> table;
		};

	}
}