#include "Interactor.h"
#include "Ui.h"

using namespace csv;
int main(int argc, char *argv[])
{
    auto displayedData= Interactor::Start({argv+1, argv+argc});
    Ui::show(displayedData);
	return 0;
}
