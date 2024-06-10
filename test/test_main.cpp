/*
 * MyFirstTest.cpp
 *
 *  Created on: Jun 4, 2024
 *      Author: andyk
 */

#include <gtest/gtest.h>


extern "C"
{
#include "../Common/testables.h"
}


#include "../Common/TrivialClass.hpp"


int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}

TEST(BasicTest, PassingTest)
{
	TrivialClass t;
	EXPECT_TRUE(t.returnsTrue());
}

TEST(BasicTest, FailingTest)
{
	TrivialClass t;
	EXPECT_TRUE(t.returnsFalse());
}

TEST(BasicCTest, PassingSumTest)
{
	int x = sum(10, 20);
	EXPECT_EQ(x, 30);
}

TEST(BasicCTest, PassingProductTest)
{
	int x = product(10, 20);
	EXPECT_EQ(x, 200);
}

