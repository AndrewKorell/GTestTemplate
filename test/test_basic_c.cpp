

#include <gtest/gtest.h>

extern "C"
{
#include "../Common/basic_c.h"
}


//No Setup or Tear Down required 

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