#include <gmock/gmock.h>
#include <string>

#include "Interactor.h"

namespace csv
{
    using namespace testing;

    TEST(InteractorTests, Start)
    {
        // Act
        const char* args[] = {"app", "testInput.csv", "40", nullptr};
        const auto page = Interactor::Start(args, 3);

        EXPECT_EQ (page.numberOfRows, 40);
        EXPECT_EQ (page.firstLine, 0);
        std::vector <std::string> header = {"one", " two", "three-"};
        EXPECT_EQ (page.header, header);
        std::vector <std::vector <std::string> > values = {{"four", " five", " six"},};
        EXPECT_EQ (page.values, values);
    }

    TEST(InteractorTests, PrevPage_ToVeryFirstPage)
    {
        contracts::Page dummyPage;
        contracts::Page returnPage;
        dummyPage.numberOfRows = 10;
        dummyPage.firstLine = 10;

        returnPage = Interactor::PrevPage(dummyPage);

        EXPECT_EQ (returnPage.firstLine, 0);
    }

    TEST(InteractorTests, PrevPage_ValidPrev)
    {
        contracts::Page dummyPage;
        contracts::Page returnPage;
        dummyPage.numberOfRows = 5;
        dummyPage.firstLine = 10;

        returnPage = Interactor::PrevPage(dummyPage);

        EXPECT_EQ (returnPage.firstLine, 5);
    }

    TEST(InteractorTests, PrevPage_OutOfRange)
    {
        contracts::Page dummyPage;
        contracts::Page returnPage;
        dummyPage.numberOfRows = 42;
        dummyPage.firstLine = 10;

        returnPage = Interactor::PrevPage(dummyPage);

        EXPECT_EQ (returnPage.firstLine, 0);
    }
}