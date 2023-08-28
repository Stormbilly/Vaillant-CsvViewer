#include "Interactor.h"
#include "Ui.h"

using namespace csv;

int main(int argc, const char** argv)
{
    std::string user_input;
    auto page = Interactor::Start(argv, argc);
    UI ui;
    
    while(true)
    {
        const auto op = ui.ShowPage(page);

        switch (op)
        {
            case contracts::AllowedOperations::NextPage:
                page = Interactor::NextPage(page);
                break;
            case contracts::AllowedOperations::LastPage:
                page = Interactor::Lastpage(page);
                break;
            case contracts::AllowedOperations::PrevPage:
                page = Interactor::PrevPage(page);
                break;
            case contracts::AllowedOperations::FirstPage:
                page = Interactor::FirstPage(page);
                break;
            case contracts::AllowedOperations::Exit:
                exit(0);
        }
    }

	return 0;
}
