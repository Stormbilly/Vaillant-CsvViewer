#pragma once
#include <vector>
#include <string>

namespace csv
{
	struct CSVFileProvider
	{
		std::vector<std::string> ReadCSVFile(const std::string& file_path);
	};
	
} // namespace csv