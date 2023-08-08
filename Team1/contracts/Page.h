#pragma once

#include <string>
#include <vector>

namespace csv
{
	namespace contracts
	{		
		class Page
		{
		public:
			std::vector <std::string> header;
			std::vector <std::vector <std::string> > values;

			unsigned int numberOfRows;
			unsigned int firstLine;
		};
	}
}
