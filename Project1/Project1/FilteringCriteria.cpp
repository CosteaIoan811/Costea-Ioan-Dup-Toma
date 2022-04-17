#include "FilteringCriteria.h"
#include <iostream>
#include <string>


DynamicArray FilteringCriteria::filter(DynamicArray& arr) {
    return DynamicArray();
}

FilterType::FilterType()
{
	type = CITY_BREAK;
}

FilterType::FilterType(int tip)
{
	if (tip == 0)type = CITY_BREAK;
	if (tip == 1)type = CRUISE;
	if (tip == 2)type = ALL_INCLUSIVE;
}

FilterPrice::FilterPrice(int i)
{
	this->price = i;
}

FilterPrice::FilterPrice()
{
	this->price = 10;
}
