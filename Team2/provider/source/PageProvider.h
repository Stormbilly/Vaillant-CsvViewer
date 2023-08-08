#pragma once
#include "Page.h"
namespace csv
{
	struct PageProvider
	{
		contracts::Page ProvidePage(const contracts::Page& csv_data, int page_number, int lines_per_page);
	};
	
} // namespace csv