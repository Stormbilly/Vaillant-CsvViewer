#include <gmock/gmock.h>
#include "provider/source/PageProvider.h"

namespace csv
{
        TEST(PageProviderTests, ReturnPage_ReturnPage1Entries3)
        {
        contracts::Page csv_data{{"Name", "Street", "PLZ"},
                                        {{"A", "S1", "1"},
                                        {"B", "S2", "2"},
                                        {"C", "S3", "3"},
                                        {"D", "S4", "4"},
                                        {"E", "S5", "5"},
                                        {"F", "S6", "6"},
                                        {"G", "S7", "7"},
                                        {"H", "S8", "8"},
                                        {"I", "S8", "9"},
                                        {"J", "S8", "10"}}};
        contracts::Page expected_page{{"Name", "Street", "PLZ"},
                                        {{"A", "S1", "1"},
                                        {"B", "S2", "2"},
                                        {"C", "S3", "3"}}};   
        PageProvider page_provider;
        contracts::Page result_page;
        result_page = page_provider.ProvidePage(csv_data, 1, 3);

        EXPECT_EQ(csv_data.Header, result_page.Header);
        EXPECT_EQ(expected_page.Rows[0], result_page.Rows[0]);
        EXPECT_EQ(expected_page.Rows[1], result_page.Rows[1]);
        EXPECT_EQ(expected_page.Rows[2], result_page.Rows[2]);
        }

        TEST(PageProviderTests, ReturnPage_ReturnPage2Entries2)
        {
        contracts::Page csv_data{{"Name", "Street", "PLZ"},
                                        {{"A", "S1", "1"},
                                        {"B", "S2", "2"},
                                        {"C", "S3", "3"},
                                        {"D", "S4", "4"},
                                        {"E", "S5", "5"},
                                        {"F", "S6", "6"},
                                        {"G", "S7", "7"},
                                        {"H", "S8", "8"},
                                        {"I", "S8", "9"},
                                        {"J", "S8", "10"}}};
        contracts::Page expected_page{{"Name", "Street", "PLZ"},
                                        {{"C", "S3", "3"},
                                        {"D", "S4", "4"}}};   
        PageProvider page_provider;
        contracts::Page result_page;
        result_page = page_provider.ProvidePage(csv_data, 2, 2);

        EXPECT_EQ(csv_data.Header, result_page.Header);
        EXPECT_EQ(expected_page.Rows[0], result_page.Rows[0]);
        EXPECT_EQ(expected_page.Rows[1], result_page.Rows[1]);
        }

        TEST(PageProviderTests, ReturnPage_ReturnPage8Entries1)
        {
        contracts::Page csv_data{{"Name", "Street", "PLZ"},
                                        {{"A", "S1", "1"},
                                        {"B", "S2", "2"},
                                        {"C", "S3", "3"},
                                        {"D", "S4", "4"},
                                        {"E", "S5", "5"},
                                        {"F", "S6", "6"},
                                        {"G", "S7", "7"},
                                        {"H", "S8", "8"},
                                        {"I", "S8", "9"},
                                        {"J", "S8", "10"}}};
        contracts::Page expected_page{{"Name", "Street", "PLZ"},
                                        {{"H", "S8", "8"}}};   
        PageProvider page_provider;
        contracts::Page result_page;
        result_page = page_provider.ProvidePage(csv_data, 8, 1);

        EXPECT_EQ(csv_data.Header, result_page.Header);
        EXPECT_EQ(expected_page.Rows[0], result_page.Rows[0]);
        }

        TEST(PageProviderTests, ReturnPage_LastPageOnly2ElementsLeft)
        {
        contracts::Page csv_data{{"Name", "Street", "PLZ"},
                                        {{"A", "S1", "1"},
                                        {"B", "S2", "2"},
                                        {"C", "S3", "3"},
                                        {"D", "S4", "4"},
                                        {"E", "S5", "5"},
                                        {"F", "S6", "6"},
                                        {"G", "S7", "7"},
                                        {"H", "S8", "8"},
                                        {"I", "S8", "9"},
                                        {"J", "S8", "10"}}};  
        PageProvider page_provider;
        contracts::Page result_page;
        result_page = page_provider.ProvidePage(csv_data, 3, 4);

        EXPECT_EQ(result_page.Rows.size(), 2);
        }

        TEST(PageProviderTests, ReturnPage_NoElementsToShow)
        {
        contracts::Page csv_data{{"Name", "Street", "PLZ"},
                                        {{"A", "S1", "1"},
                                        {"B", "S2", "2"},
                                        {"C", "S3", "3"},
                                        {"D", "S4", "4"},
                                        {"E", "S5", "5"},
                                        {"F", "S6", "6"},
                                        {"G", "S7", "7"},
                                        {"H", "S8", "8"},
                                        {"I", "S8", "9"},
                                        {"J", "S8", "10"}}};  
        PageProvider page_provider;
        contracts::Page result_page;
        result_page = page_provider.ProvidePage(csv_data, 6, 4);

        EXPECT_EQ(result_page.Rows.size(), 0);
        }
}
