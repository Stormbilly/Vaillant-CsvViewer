#pragma once

#include "Page.h"

namespace csv
{
	struct UI
	{

		std::vector<uint16_t> ComputeLength(const contracts::Page& page);
	    
		std::string BuildOutputLine(const std::vector<std::string>& strings, std::vector<uint16_t> length);

		void ShowPage(const contracts::Page& page);
	};
} // namespace csv
