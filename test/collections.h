
#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include <gtest/gtest.h>

class IntCollection : public testing::Test {

 protected:
  // TearDown() is invoked immediately after a test finishes.  Here we
  // check if the test was too slow.
  void TearDown() override {
    // Gets the time when the test finishes
    const time_t end_time = time(nullptr);\
    // if(table != nullptr && table != NULL)
    // {
    //     delete table;
    //     table = nullptr;
    // }

    // Asserts that the test took no more than ~5 seconds.  Did you
    // know that you can use assertions in SetUp() and TearDown() as
    // well?
    printf("%jd ", end_time - start_time_);
    EXPECT_TRUE(end_time - start_time_ <= 5) << "The test took too long.";
  }

  // The UTC time (in seconds) when the test starts
  time_t start_time_;

public:
  //make_unique<int>()  
  
  int * table;
  size_t table_size;

};


class IntCollectionSmall: public IntCollection {
 protected:
  // Remember that SetUp() is run immediately before a test starts.
  // This is a good place to record the start time.
  void SetUp() override 
  { 
        start_time_ = time(nullptr); 
        table = new int[7] { 10, 20, 22, 30, 33, 88, 106 };
        table_size = 7;
  }

};


class IntCollectionLargeOdd : public IntCollection {
 protected:
  // Remember that SetUp() is run immediately before a test starts.
  // This is a good place to record the start time.
  void SetUp() override 
  { 

        start_time_ = time(nullptr); 
        //all odd numbers between -32768 32767 
        table = new int[32768];
        for(int i=0; i < 32768; i++)
        {
            table[i] = (-32767) + (i * 2);
        }
        table_size = 32768;
  }

};


class IntCollectionLargeEven : public IntCollection {
 protected:
  // Remember that SetUp() is run immediately before a test starts.
  // This is a good place to record the start time.
  void SetUp() override 
  { 

        start_time_ = time(nullptr); 
        //all Even numbers between -32768 32767 
        table = new int[32768];
        for(int i=0; i < 32768; i++)
        {
            table[i] = (-32768) + (i * 2);
        }
        table_size = 32768;
  }
};

#endif 