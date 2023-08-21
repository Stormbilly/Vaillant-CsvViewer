#include <vector>
#include <iostream>
#include <algorithm>
#include "Ui.h"

namespace csv
{
	
    std::vector<uint16_t> UI::ComputeLength(const contracts::Page& page) {
        std::vector<uint16_t> length;
        for(auto elem:  page.header) {
            length.push_back(elem.length());
        } 
        // for(auto lineElements: page.values) {
        //     if (lineElements.)
        // }
        return length;
    }

    void UI::ShowPage(const contracts::Page& page) {
        ::system("clear");
        std::vector<uint16_t> length = ComputeLength(page);

        std::cout  << BuildOutputLine(page.header, length).data();
        std::cout << "--------------------------------------\n";
        
        unsigned int limit = std::min ((unsigned int)(page.firstLine + page.numberOfRows), (unsigned int)page.values.size());
        
        for (int i = page.firstLine; i < limit ; i++) {
            std::cout << BuildOutputLine(page.values[i], length).data();
        }
        std::cout << "--------------------------------------\n";
        std::cout << "F)irst page, P)revious page, N)ext page, Last page, E)xit\n";
    } 
 
    std::string UI::BuildOutputLine(const std::vector<std::string>& strings, std::vector<uint16_t> length) {
        
        std::string output;
        
        for (const auto& it : strings) {
            output.append(it +  "|");
        }; 
        output.append("\n");
        return output;
    }           
} // namespace csv
