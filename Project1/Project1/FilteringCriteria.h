#pragma once
#include "DynamicArray.h"
#include <string>
//#include "Offer.h"
// you can add all your filtering classes in this module


class FilteringCriteria
{public:
	virtual DynamicArray filter(DynamicArray& da);

};
//this clase inherits from filtering criteria

class FilterPrice:public FilteringCriteria{
private:
	float price=0;

public:
	inline void set_price(unsigned int i) { this->price = i; }
	FilterPrice(int i);
	FilterPrice();
	DynamicArray filter(DynamicArray& arr) {
		DynamicArray result;
		for (int i = 0; i < arr.getLength(); i++) {
			Offer a = arr.get(i);
			if (a.get_price() <= price) {
				result.append(a);
				
			}
		}
		return result;
	}

};
class FilterType :public FilteringCriteria {
private:
	OfferType type;
public:
	inline void set_type(int tip){
		if (tip == 0)type = CITY_BREAK;
		if (tip == 1)type = CRUISE;
		if (tip == 2)type = ALL_INCLUSIVE;
	}
	FilterType();
	FilterType(int tip);
	DynamicArray filter(DynamicArray& arr) {
		DynamicArray result;
		/*
		cout << "Ce tip?"<<endl;
		cout << "0.City Break " << endl << "1.Cruise" << endl << "2.All Inclusive" << endl;
		string tip;
		cin >> tip;
		if (tip == "0")type = CITY_BREAK;
		if (tip == "1")type = CRUISE;
		if (tip == "2")type = ALL_INCLUSIVE;
		*/

		for (int i = 0; i < arr.getLength(); i++) {
			Offer a = arr.get(i);
			if (a.get_type() == type) { result.append(a); }
		}
		return result;
	}

};
class FilterDeparture :public FilteringCriteria {
private:string loc;

public:
	FilterDeparture(string loc);
	DynamicArray filter(DynamicArray& arr) {
		DynamicArray result;
		for (int i = 0; i < arr.getLength(); i++) {
			Offer a = arr.get(i);
			if (a.get_destination() == loc) { result.append(a); }
		}
		return result;
	}


};



class FilterTP :public FilteringCriteria {//type price
private:
	FilterPrice fp;
	FilterType ft;
public:
	inline void setter(int price, int tip) {
		if (tip == 0)ft.set_type(CITY_BREAK);
		if (tip == 1)ft.set_type(CRUISE);
		if (tip == 2)ft.set_type(ALL_INCLUSIVE);
		fp.set_price(price);

	}
	DynamicArray filter(DynamicArray& arr) {
		DynamicArray result = fp.filter(arr);
		result = ft.filter(result);
		return result;
	}
};

class FilterAnd :public FilteringCriteria {
public:
	FilteringCriteria criteria;
	FilteringCriteria otherCriteria;
public:
	FilterAnd(FilteringCriteria criteria1, FilteringCriteria otherCriteria1);

	DynamicArray filter(DynamicArray& arr) {
		DynamicArray result;
		result = criteria.filter(arr);
		cout << result;
		//result = otherCriteria.filter(result);
		
		return result;
	}
};