/*
 * MyFirstTest.cpp
 *
 *  Created on: Jun 4, 2024
 *      Author: andyk
 */

#include <gtest/gtest.h>

TEST(MyFirstTestClass, ThisTestPasses)
{
	SUCCEED();
}

TEST(MyFirstTestClass, ThisTestFails)
{
	int a = 4, b = 6;
	int sum = a + b;
	ASSERT_EQ(sum, 10);
}


