#include <vector>
#include <iostream>
#include <algorithm>
#include "Ui.h"

namespace csv
{
	
    uint16_t UI::NumberofElementsInLengthVector(const contracts::Page& page) {
        uint16_t numberOfElemets = page.header.size();
        for(auto elem:  page.values) {
            numberOfElemets = std::max(numberOfElemets, (uint16_t)elem.size());
        } 
        return numberOfElemets;
    }

    std::vector<uint16_t> UI::ComputeLengthOfCells(const contracts::Page& page) {
        std::vector<uint16_t> length(NumberofElementsInLengthVector(page), uint16_t);
        uint16_t i = 0L;
        for(auto elem:  page.header) {
            length[i] = std::max(length[i], elem.length());;
        } 
        for(auto lineElements: page.values) {
            i = 0L;
            for(auto elem:  lineElements) {
                length[i] = std::max(length[i], elem.length());;
            } 
        }
        return length;
    }

    void UI::ShowPage(const contracts::Page& page) {
        ::system("clear");
        std::vector<uint16_t> length = ComputeLengthOfCells(page);

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
