#include <gtest/gtest.h>
#include "collections.h"

extern "C"
{
#include "../Common/search_array.h"
}


namespace
{
    class SearchTestIt : public IntCollectionSmall {};

    TEST_F(SearchTestIt, FindValueInMiddle)
    {        
        int key = 30;
        int x = find_value(table_size, table, key);
        EXPECT_EQ(x, 1);
    }
    
    TEST_F(SearchTestIt, NotFindValueInMiddle)
    {
        int values[] = {10, 20, 22, 30, 33, 88, 106 };
        int key = 31;
        size_t size = 7;
        int x = find_value(table_size, table, key);
        EXPECT_EQ(x, 0);
    }

    TEST_F(SearchTestIt, FindFirstValueInArray)
    {
        int values[] = {10, 20, 22, 30, 33, 88, 106 };
        int key = 106;
        size_t size = 7;
        int x = find_value(table_size, table, key);
        EXPECT_EQ(x, 1);
    }

    TEST_F(SearchTestIt, FindLastValueInArray)
    {
        int values[] = {10, 20, 22, 30, 33, 88, 106 };
        int key = 106;
        size_t size = 7;
        int x = find_value(size, values, key);
        EXPECT_EQ(x, 1);
    }

    TEST_F(SearchTestIt, EmtpyArray)
    {
        int * values = nullptr;
        int key = 30;
        size_t size = 0;
        int x = find_value(size, values, key);
        EXPECT_EQ(x, 0);
    }

    TEST_F(SearchTestIt, FindInArrayOfTwo)
    {
        int values[2] = { 30, 40 };
        int key = 30;
        size_t size = 7;
        int x = find_value(size, values, key);
        EXPECT_EQ(x, 1);
    }

    class SearchTestItLarge : public IntCollectionLargeEven {};

    TEST_F(SearchTestItLarge, LargeCollectionStart)
    {
        int key = -32766;
        int x = find_value(table_size, table, key);
        EXPECT_EQ(x, 1);
    }

    TEST_F(SearchTestItLarge, LargeCollectionEnd)
    {
        int key = 32766;
        int x = find_value(table_size, table, key);
        EXPECT_EQ(x, 1);
    }

    TEST_F(SearchTestItLarge, LargeCollectionEndMiss)
    {
        int key = 32765;
        int x = find_value(table_size, (int *)table, key);
        EXPECT_EQ(x, 0);
    }
}

//::testing::Range(size_t{0}, size_t{5})
//}// end name space 

