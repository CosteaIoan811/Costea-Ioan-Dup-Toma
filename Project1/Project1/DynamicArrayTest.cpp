#include "DynamicArrayTest.h"

void DynamicArrayTest::runAllTests()
{
	std::cout << "Creation test...";
	creationTest();
	std::cout << "AppendTest test...";
	appendTest();
	std::cout << "GetTest test...";
	getTest();
	std::cout << "Equality test...";
	EqualityTest();
	std::cout << "Dynamic Array.h test end\n";
}
int DynamicArrayTest::creationTest() {
	DynamicArray a;
	assert(a.getCapacity() == 100);
	assert(a.getLength() == 0);
	a = DynamicArray(10);
	assert(a.getCapacity() == 10);
	assert(a.getLength() == 0);
	return 0;
}
int DynamicArrayTest::appendTest() {
	DynamicArray arr(2);
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	Offer a1("id2", 42, "Alba", "20.3.2022", "25.3.2022", CITY_BREAK);
	arr.append(a);
	assert(arr.getCapacity() == 2);
	assert(arr.getLength() == 1);
	arr.append(a1);
	assert(arr.getLength() == 2);
	assert(arr.getCapacity() == 2);
	arr.append(a1);
	assert(arr.getLength() == 3);
	assert(arr.getCapacity() == 4);
	return 0;
}

int DynamicArrayTest::getTest()
{
	DynamicArray arr(2);
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	Offer a1("id2", 42, "Alba", "20.3.2022", "25.3.2022", CITY_BREAK);
	arr.append(a);
	arr.append(a1);
	assert(arr.get(0).get_id() == "id1");
	assert(arr.get(1).get_id() == "id2");
	assert(arr.get(0).get_price() == 3);
	assert(arr.get(1).get_type() == CITY_BREAK);
	assert(arr.get(0).get_date_start() == "20.3.2022");
	assert(arr.get(0).get_date_end() == "23.3.2022");
	assert(arr.get(0).get_destination() == "Bucuresti");
	return 0;
}

int DynamicArrayTest::EqualityTest()
{
	DynamicArray arr(2);
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	Offer a1("id2", 42, "Alba", "20.3.2022", "25.3.2022", CITY_BREAK);
	arr.append(a);
	arr.append(a1);
	DynamicArray arr2 = arr;
	assert(arr.getCapacity() == 2);
	assert(arr2.getCapacity() == 2);
	assert(arr.getLength() == 2);
	assert(arr2.getLength() == 2);
	arr.append(a);
	arr2 = arr;
	assert(arr.getLength() == 3);
	assert(arr2.getLength() == 3);

	return 0;
}
