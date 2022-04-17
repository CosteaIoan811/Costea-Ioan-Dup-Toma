#pragma once
#include <iostream>
#include <cassert>
#include "FilteringCriteria.h"
#include "DynamicArray.h"
class FilteringTest
{
public:
	static void runAllTests();
private:
	static int filter1();
	static int filter2();
	static int filter3();
};

