#include <gtest/gtest.h>
#include "collections.h"

extern "C"
{
#include "../Common/search_array.h"
}

TEST(SearchTestRecGuard, EmtpyCollection)
{
    int key = 30;
    int initial_offset = 0;
    size_t table_size = 0;
    int table[1];

    int x = find_value_recursive(table_size, table, key, 0);
	EXPECT_EQ(x, 0);
}


TEST(SearchTestRecGuard, NullTableCollection)
{
    int key = 30;
    int initial_offset = 0;
    size_t table_size = 10;

    int x = find_value_recursive(table_size, nullptr, key, 0);
	EXPECT_EQ(x, 0);
}

class SearchTestRec : public IntCollectionSmall {};

TEST_F(SearchTestRec, FindableInSmallCollection)
{
    int key = 30;
    int intial_offset = 0;
	int x = find_value_recursive(table_size, table, key, 0);
	EXPECT_EQ(x, 1);
}

TEST_F(SearchTestRec, NotfindableInSmallCollection)
{

    int key = 31;
    int intial_offset = 0;
	int x = find_value_recursive(table_size, table, key, 0);
	EXPECT_EQ(x, 0);
}


class SearchTestLargeEvenRec : public IntCollectionLargeEven {};

TEST_F(SearchTestLargeEvenRec, FindNearEndLargeCollection)
{

    int key = 32764;
    int intial_offset = 0;
	int x = find_value_recursive(table_size, table, key, 0);
	EXPECT_EQ(x, 1);
}

TEST_F(SearchTestLargeEvenRec, NotFindNearEndLargeCollection)
{

    int key = 32763;
    int intial_offset = 0;
	int x = find_value_recursive(table_size, table, key, 0);
	EXPECT_EQ(x, 0);
}

TEST_F(SearchTestLargeEvenRec, FindNearBeginningLargeCollection)
{

    int key = 4;
    int intial_offset = 0;
	int x = find_value_recursive(table_size, table, key, 0);
	EXPECT_EQ(x, 1);
}

TEST_F(SearchTestLargeEvenRec, NotFindNearBeginningLargeCollection)
{

    int key = 3;
    int intial_offset = 0;
	int x = find_value_recursive(table_size, table, key, 0);
	EXPECT_EQ(x, 0);
}

TEST_F(SearchTestLargeEvenRec, FindLastInLargeCollection)
{

    int key = 32766;
    int intial_offset = 0;
	int x = find_value_recursive(table_size, table, key, 0);
	EXPECT_EQ(x, 1);
}

TEST_F(SearchTestLargeEvenRec, FindFirstInLargeCollection)
{

    int key = -32768;
    int intial_offset = 0;
	int x = find_value_recursive(table_size, table, key, 0);
	EXPECT_EQ(x, 1);
}