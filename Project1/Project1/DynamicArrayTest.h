#pragma once
#include <iostream>
#include <cassert>
#include "DynamicArray.h"
class DynamicArrayTest
{
public:
	static void runAllTests();
private:
	static int creationTest();
	static int appendTest();
	static int getTest();
	static int EqualityTest ();
};

