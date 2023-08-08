#pragma once
#include <vector>
#include <string>
#include "Page.h"
namespace csv
{
	struct CSVFileParser
	{
		contracts::Page ParseCSV(const std::vector<std::string>& csv_file_data);
	};
	
} // namespace csv