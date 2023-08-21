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
        std::vector <std::string> header = {"one", " two", " three-"};
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

    TEST(InteractorTests, NestPageNormal)
    {
        // Arrange
        contracts::Page page;
        page.numberOfRows = 10;
        page.firstLine = 0;
        page.values.insert(page.values.end(), 30,  { {"four", " five", " six"} });

        // Act
        const auto result = Interactor::NextPage(page);

        // Assert
        EXPECT_EQ (result.firstLine, 10);
    }

    TEST(InteractorTests, NestPage_Wrap)
    {
        // Arrange
        contracts::Page page;
        page.numberOfRows = 10;
        page.firstLine = 14;
        page.values.insert(page.values.end(), 20,  { {"four", " five", " six"} });

        // Act
        const auto result = Interactor::NextPage(page);

        // Assert
        EXPECT_EQ (result.firstLine, 10);
    }

    TEST(InteractorTests, NestPage_End)
    {
        // Arrange
        contracts::Page page;
        page.numberOfRows = 10;
        page.firstLine = 10;
        page.values.insert(page.values.end(), 20,  { {"four", " five", " six"} });

        // Act
        const auto result = Interactor::NextPage(page);

        // Assert
        EXPECT_EQ (result.firstLine, 10);
    }

    TEST(InteractorTests, FirstPage)
    {
        // Arrange
        contracts::Page page;
        page.numberOfRows = 10;
        page.firstLine = 8;
        page.values.insert(page.values.end(), 20,  { {"four", " five", " six"} });

        // Act
        const auto result = Interactor::FirstPage(page);

        // Assert
        EXPECT_EQ (result.firstLine, 0);
    }

    TEST(InteractorTests, LastPage)
    {
        contracts::Page page;
        page.numberOfRows = 2;
        std::vector <std::vector <std::string> > values = {{"four", " five", " six"},{"four", " five", " six"},{"four", " five", " six"}};
        page.values = values;

        const auto lastPage = Interactor::Lastpage(page);

        EXPECT_EQ (lastPage.firstLine, 1);
    }

 

    TEST(InteractorTests, LastPage_SameNoOfRows)
    {
        contracts::Page page;
        page.numberOfRows = 3;
        std::vector <std::vector <std::string> > values = {{"four", " five", " six"},{"four", " five", " six"},{"four", " five", " six"}};
        page.values = values;

        const auto lastPage = Interactor::Lastpage(page);

        EXPECT_EQ (lastPage.firstLine, 0);
    }

 

    TEST(InteractorTests, LastPage_NoOfRowsHigher)
    {
        contracts::Page page;
        page.numberOfRows = 4;
        std::vector <std::vector <std::string> > values = {{"four", " five", " six"},{"four", " five", " six"},{"four", " five", " six"}};
        page.values = values;

        const auto lastPage = Interactor::Lastpage(page);

        EXPECT_EQ (lastPage.firstLine, 0);
    }
}
