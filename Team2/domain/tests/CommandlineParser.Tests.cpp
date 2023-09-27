#include <gmock/gmock.h>
#include <string>

#include "Interactor.h"
#include "CommandlineParser.h"

namespace csv
{
	using namespace testing;

 	TEST(CommandlineParserTests, ParseCommandline_NoArgs)
	{
        CommandlineParser parser;

		char **argv = nullptr;
        int argc = 0;

        EXPECT_THROW(parser.ParseCommandline(argv, argc), std::out_of_range);
    } 

    TEST(CommandlineParserTests, ParseCommandline_Filename_Only)
	{
        CommandlineParser parser;

		char *argv[] = {"Programm", "Test"};
        int argc = 2;
        
        auto [filename, page_size] = parser.ParseCommandline(argv, argc);
        
        EXPECT_FALSE(filename.empty());
        EXPECT_EQ(page_size, 3);
 
	} 

    TEST(CommandlineParserTests, ParseCommandline_Filename_And_PageSize)
	{
        CommandlineParser parser;

		char *argv[] = {"Programm", "Test", "40"};
        int argc = 3;

        auto [filename, page_size] = parser.ParseCommandline(argv, argc);
        
        EXPECT_FALSE(filename.empty());
        EXPECT_EQ(page_size, 40);
 	}

    TEST(CommandlineParserTests, ParseCommandline_TooManyArgs)
	{
        using namespace std::string_literals;
        CommandlineParser parser;

        char *argv[] = {"Programm", "Test", "40", "e", "34"};
        int argc = 5;

        auto [filename, page_size] = parser.ParseCommandline(argv, argc);
        
        EXPECT_FALSE(filename.empty());
        EXPECT_EQ(page_size, 40);
 	} 

    TEST(CommandlineParserTests, ParseCommandline_Invalid_PageSize)
	{
        CommandlineParser parser;

		char *argv[] = {"Programm", "Test", "AB"};
        int argc = 3;

        EXPECT_THROW(parser.ParseCommandline(argv, argc), std::invalid_argument);
 	}

    TEST(CommandlineParserTests, ParseCommandline_PageSize_TooSmall)
	{
        CommandlineParser parser;

		char *argv[] = {"Programm", "Test", "0"};
        int argc = 3;

        EXPECT_THROW(parser.ParseCommandline(argv, argc), std::out_of_range);
 	}

    TEST(CommandlineParserTests, ParseCommandline_PageSize_Negative)
	{
        CommandlineParser parser;

		char *argv[] = {"Programm", "Test", "-1"};
        int argc = 3;

        EXPECT_THROW(parser.ParseCommandline(argv, argc), std::out_of_range);
 	}


    TEST(CommandlineParserTests, ParseCommandline_Exception)
	{
        CommandlineParser parser;

		char *argv[] = {"Programm"};
        int argc = 1;
       
        EXPECT_THROW(parser.ParseCommandline(argv, argc), std::out_of_range);
 	}

}