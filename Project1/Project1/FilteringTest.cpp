#include "FilteringTest.h"

void FilteringTest::runAllTests()
{
	std::cout << "Filter test...";
	filter1();
	filter2();
	filter3();
		std::cout << "Filter test...end \n";
}

int FilteringTest::filter1()
{
	FilterPrice fPrice;
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	Offer a1("id2", 42, "Alba", "20.3.2022", "25.3.2022", CITY_BREAK);
	DynamicArray arr;
	arr.append(a);
	arr.append(a1);
	fPrice.set_price(10);
	arr = fPrice.filter(arr);
	assert(arr.getLength() == 1);
	fPrice.set_price(1);
	arr.append(a1);
	arr = fPrice.filter(arr);
	assert(arr.getLength() == 0);
	arr.append(a);
	arr.append(a1);
	fPrice.set_price(50);
	arr = fPrice.filter(arr);
	assert(arr.getLength() == 2);


	return 0;
}
int FilteringTest::filter2() {
	FilterType fType;
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	Offer a1("id2", 42, "Alba", "20.3.2022", "25.3.2022", CITY_BREAK);
	DynamicArray arr;
	arr.append(a);
	arr.append(a1);
	fType.set_type(0);
	arr = fType.filter(arr);
	assert(arr.getLength() == 1);
	cout << arr;
	arr.append(a);
	fType.set_type(1);
	arr = fType.filter(arr);
	assert(arr.getLength() == 1);
	fType.set_type(2);
	arr = fType.filter(arr);
	assert(arr.getLength() == 0);
	return 0;
}

int FilteringTest::filter3()
{
	FilterTP fTP;
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	Offer a1("id2", 42, "Alba", "20.3.2022", "25.3.2022", CITY_BREAK);
	DynamicArray arr;
	arr.append(a);
	arr.append(a1);
	fTP.setter(50, 0);
	arr = fTP.filter(arr);
	assert(arr.getLength() == 1);
	fTP.setter(2, 0);
	arr = fTP.filter(arr);
	assert(arr.getLength() == 0);
	arr.append(a);
	arr.append(a1);
	fTP.setter(30, 0);
	arr = fTP.filter(arr);
	assert(arr.getLength() == 0);

	return 0;
}
