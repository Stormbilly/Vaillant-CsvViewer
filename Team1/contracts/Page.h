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

			Page (std::vector <std::vector <std::string> > csv, unsigned int numberOfRows) {
				this->firstLine = 0;
				this->numberOfRows = numberOfRows;

				if(csv.size() > 2)
				{
					this->header = csv[0];
					this->values = csv;
					this->values.erase(this->values.begin());
				}
			}
		};
	}
}
