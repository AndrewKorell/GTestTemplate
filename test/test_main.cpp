/*
 * MyFirstTest.cpp
 *
 *  Created on: Jun 4, 2024
 *      Author: andyk
 */

#include <gtest/gtest.h>


#include "../Common/TrivialClass.hpp"


int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}




