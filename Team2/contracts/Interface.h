#pragma once
#include <string>
#include <vector>

namespace csv
{
	namespace contracts
	{
		struct CSV_File
		{
			std::string filename;
		};
		
		struct Page
		{
			std::vector<std::string> Header;
			std::vector<std::string> Rows;
		};
	}
}