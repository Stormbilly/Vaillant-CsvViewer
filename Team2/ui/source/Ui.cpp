#include "Ui.h"
#include <iostream>
#include <iomanip>
namespace csv
{
    void Ui::ShowPage(const contracts::Page& page)
    {
        //print header
        for(auto& elem : page.Header)
        {
            std::cout << elem << " " << "|";
        }
        std::cout << std::endl;

        for(auto elem : page.Header)
        {
            std::cout << std::setfill('-') << std::setw(elem.size() + 2) << "+";
        }
        std::cout << std::endl;

        for(auto& row : page.Rows)
        {
            for(auto& elem: row)
            {
                std::cout << elem << " " << "|";
            }
            std::cout << std::endl;
        }

        std::cout << "F)irst page, P)revious page, N)ext page, L)ast page, E)xit" << std::endl;
    }

} // namespace csv
