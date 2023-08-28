#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
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
        std::vector<uint16_t> length((size_t) NumberofElementsInLengthVector(page));
        uint16_t i = 0L;
        for(auto elem:  page.header) {
            length[i] = std::max((size_t)length[i], elem.length());;
            i++;
        } 
        for(auto lineElements: page.values) {
            i = 0L;
            for(auto elem:  lineElements) {
                length[i] = std::max((size_t)length[i], elem.length());;
                ++i;
            } 
        }
        return length;
    }

    contracts::AllowedOperations  UI::ShowPage(const contracts::Page& page) {
        ::system("clear");

        // Compute Length of columms
        std::vector<uint16_t> length = ComputeLengthOfCells(page);

        // Print header
        std::cout  << BuildOutputLine(page.header, length);

        // One line with minuses: --------
        const auto sum_of_minuses = std::accumulate(length.begin(), length.end(), 0) + length.size();
        const std::string minus_line(sum_of_minuses, '-');
        std::cout << minus_line << std::endl;

        // Print body
        unsigned int limit = std::min ((unsigned int)(page.firstLine + page.numberOfRows), (unsigned int)page.values.size());
        for (int i = page.firstLine; i < limit ; i++) {
            std::cout << BuildOutputLine(page.values[i], length);
        }

        // One line with minuses: --------
        std::cout << minus_line << std::endl;

        // Help line
        std::cout << "F)irst page, P)revious page, N)ext page, L)ast page, E)xit\n";

        while (true)
        {
            // Process Input
            std::string user_input;
            std::cin >> user_input;

            if(user_input == "F")
                return contracts::AllowedOperations::FirstPage;
            else if(user_input == "P")
                return contracts::AllowedOperations::PrevPage;
            else if(user_input == "N")
                return contracts::AllowedOperations::NextPage;
            else if(user_input == "L")
                return contracts::AllowedOperations::LastPage;
            else if(user_input == "E")
                return contracts::AllowedOperations::Exit;
            else
            {
                std::cout << "Invalid command" << std::endl;
            }
        } 
    } 
 
    std::string UI::BuildOutputLine(const std::vector<std::string>& strings, std::vector<uint16_t> length) {
        
        std::string output;
        
        unsigned int i = 0; 
        for (const auto& it : strings) {

            const auto countWhitesspaces = length [i] - it.length();
            const std::string whitespaces(countWhitesspaces, ' ');
            output.append(whitespaces);
            ++i;

            output.append(it +  "|");
        }; 
        output.append("\n");
        return output;
    }           
} // namespace csv
