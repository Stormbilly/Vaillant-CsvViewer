#pragma once
#include <string>
#include <tuple>
namespace csv
{
	struct CommandlineParser
	{
		std::tuple<std::string, int> ParseCommandline(char** argv, int argc);
	};
	
} // namespace csv