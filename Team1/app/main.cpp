#include "Interactor.h"
#include "Ui.h"
#include <iostream>

using namespace csv;

int main(int argc, const char** argv)
{
    std::string user_input;
    bool errorFlag = false;
    auto page = Interactor::Start(argv, argc);

    while(true)
    {
        ShowPage(page);

        if(errorFlag)
        {
            std::cout << "Invalid command" << std::endl;
            errorFlag = false;
        }

        std::cin >> user_input;

        if(user_input == "F")
            page = Interactor::NextPage(page);
        else if(user_input == "P")
            page = Interactor::PrevPage(page);
        else if(user_input == "N")
            page = Interactor::NextPage(page);
        //else if(user_input == "L")
        //    page = Interactor::LastPage(page);
        else if(user_input == "E")
            exit(0);
        else
            errorFlag = true;
    }

	return 0;
}
