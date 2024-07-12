cmake_minimum_required(VERSION 3.14)
project(tests)


set(CMAK
E_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED_ON)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

message(STATUS "CC set to: $ENV{CC}")
message(STATUS "CXX set to:$ENV{CXX}")

enable_testing()

add_executable(
	hello_test 
	hello_test.cpp
)

add_executable(       #declaure an excutable test_basic_c using test_basic_c.cpp for source
    test_basic_c      
    test_basic_c.cpp
)

add_executable(
    test_search_array_it
    test_search_array_it.cpp
)

add_executable(
    test_search_array_rec
    test_search_array_rec.cpp
)

add_executable(
	test_main
	test_main.cpp
)


target_link_libraries(
	test_main PUBLIC
    GTest::gtest_main
	GTest::gtest
)

target_link_libraries(  # connect basic_c and GTest::gtest_main to test_basic_C
	test_basic_c
    basic_c
	GTest::gtest_main
)

target_link_libraries( 
	test_search_array_it
    search_array
	GTest::gtest_main
)

target_link_libraries( 
	test_search_array_rec
    search_array
	GTest::gtest_main
)

target_link_libraries(
	hello_test
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)  #test to include, don't have to include everything 
gtest_discover_tests(test_basic_c)
gtest_discover_tests(test_search_array_it)
gtest_discover_tests(test_search_array_rec)
gtest_discover_tests(test_main)



