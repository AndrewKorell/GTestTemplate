"# GTestTemplate" 

This is a working demonstration of a Unit Test wihtin an STM32 project. There will be further instructions for integrating into a CubeIDE project with microprocessor code. 

To run tests select: **Run**->**Run Configuration**-->**C/C++ Testing (Tab)** then set **Runner** to **Google Test Runner** then press **Run** button.


To run in command prompt:

navigate to main folder:

	cmake -S . -B build
	...output not shown ...
	
	
	cmake --build build 
	... output not shown ....

	
	cd build

	cd test

	ctest 


	C:\git\STMProjects\Nucleo_446ZE\GTestTemplate\build\test>ctest
	Test project C:/git/STMProjects/Nucleo_446ZE/GTestTemplate/build/test
	    Start 1: HelloTest.BasicAssertions
	1/4 Test #1: HelloTest.BasicAssertions ........   Passed    0.01 sec
	    Start 2: BasicTest.PassingTest
	2/4 Test #2: BasicTest.PassingTest ............   Passed    0.02 sec
	    Start 3: BasicCTest.PassingSumTest
	3/4 Test #3: BasicCTest.PassingSumTest ........   Passed    0.02 sec
	    Start 4: BasicCTest.PassingProductTest
	4/4 Test #4: BasicCTest.PassingProductTest ....   Passed    0.01 sec
	
	100% tests passed, 0 tests failed out of 4
	
	Total Test time (real) =   0.11 sec



## References ##

[Unit testing in STM32CubeIDE with GoogleTest](https://kleinembedded.com/unit-testing-in-stm32cubeide-with-googletest/)

[Introduction to Google Test: An Open Source C/C++ Unit-Testing Framework](https://betterprogramming.pub/introduction-to-google-test-an-open-source-c-c-unit-testing-framework-ec517f4a22d2)