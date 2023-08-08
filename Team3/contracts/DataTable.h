#pragma once
#include <string>
#include <vector>
#include <list>

namespace csv
{
	namespace contracts
	{
		struct DataTable
		{
			std::list <std::vector <std::string>> table;
		};

	}
}