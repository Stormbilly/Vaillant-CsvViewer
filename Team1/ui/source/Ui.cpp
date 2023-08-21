#include <vector>
#include <iostream>
#include <algorithm>
#include "Ui.h"

namespace csv
{
	
    std::string BuildOutputLine(const std::vector<std::string>& strings);

    void ShowPage(const contracts::Page& page) {
        ::system("clear");

        std::cout  << BuildOutputLine(page.header).data();
        std::cout << "--------------------------------------\n";
        
        unsigned int limit = std::min ((unsigned int)(page.firstLine + page.numberOfRows), (unsigned int)page.values.size());
        
        for (int i = page.firstLine; i < limit ; i++) {
            std::cout << BuildOutputLine(page.values[i]).data();
        }
        std::cout << "--------------------------------------\n";
        std::cout << "F)irst page, P)revious page, N)ext page, Last page, E)xit\n";
    } 
 
    std::string BuildOutputLine(const std::vector<std::string>& strings) {
        
        std::string output;
        
        for (const auto& it : strings) {
            output.append(it +  "|");
        }; 
        output.append("\n");
        return output;
    }           
} // namespace csv
