#pragma once
#include "Page.h"

namespace csv
{
	struct Interactor
	{
		contracts::Page Start(char** argv, int argc);
		int page_number=1;
	};
	
} // namespace csv
