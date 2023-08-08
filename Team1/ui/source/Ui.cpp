#include <vector>
#include <iostream>
#include "Ui.h"

namespace csv
{
	
    std::string BuildOutputLine(const std::vector<std::string>& strings);

    void ShowPage(const contracts::Page& page) {
        ::system("clear");

        std::cout  << BuildOutputLine(page.header).data();
        std::cout << "--------------------------------------\n";
        
        
        for (int i = page.firstLine; i < page.firstLine + page.numberOfRows; i++) {
//        for (auto itVec = page.values[page.firstLine]; itVec != page.values[page.firstLine + page.numberOfRows]; itVec++) { 
                std::cout << BuildOutputLine(page.values[i]).data();
        }
        std::cout << "--------------------------------------\n";
        std::cout << "F)irst page, P)revious page, N)ext page, Last page, E)xit\n";

    } 

    std::string BuildOutputLine(const std::vector<std::string>& strings) {
        
        std::string output;
        
        for (auto itVec = strings.begin(); itVec != strings.end(); itVec++) {
            output.append(*itVec +  "|");
        }; 
        output.append("\n");
        return output;
    }           
} // namespace csv
