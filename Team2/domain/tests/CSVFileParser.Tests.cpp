#include <gmock/gmock.h>
#include "Interactor.h"
#include "CSVFileParser.h"
#include <iostream>

namespace csv
{
        using namespace testing;

        TEST(CSVFileParserTests, ParseValidCSV)
        {
                const std::vector<std::string> csv_data{{"Name;Street;PLZ"},
                                                        {"A;S1;1"},
                                                        {"B;S2;2"},
                                                        {"C;S3;3"}};
                CSVFileParser parser;
                auto page = parser.ParseCSV(csv_data);
                EXPECT_EQ("Name", page.Header[0]);
                EXPECT_EQ("Street", page.Header[1]);
                EXPECT_EQ("PLZ", page.Header[2]);
                EXPECT_EQ("A", page.Rows[0][0]);
                EXPECT_EQ("S1", page.Rows[0][1]);
                EXPECT_EQ("1", page.Rows[0][2]);
                EXPECT_EQ("B", page.Rows[1][0]);
                EXPECT_EQ("S2", page.Rows[1][1]);
                EXPECT_EQ("2", page.Rows[1][2]);
                EXPECT_EQ("C", page.Rows[2][0]);
                EXPECT_EQ("S3", page.Rows[2][1]);
                EXPECT_EQ("3", page.Rows[2][2]);
        }
}
