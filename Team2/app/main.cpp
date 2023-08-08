#include "Ui.h"
#include "Interactor.h"

int main(int argc, char** argv)
{
    csv::Interactor interactore;
    csv::Ui ui;
    auto page = interactore.Start(argv, argc);
    ui.ShowPage(page);
    return 0;
}