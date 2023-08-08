#include "Interactor.h"
#include "Ui.h"

using namespace csv;

int main(int argc, const char** argv)
{
    const auto page = Interactor::Start(argv, argc);
    ShowPage(page);

	return 0;
}
