#pragma once
#include <string>
#include <iostream>
using namespace std;
typedef enum {
	CITY_BREAK,
	CRUISE,
	ALL_INCLUSIVE

}OfferType;
class Offer
{public://geters-setters
	inline void set_price(unsigned int i) { this->price = i; }
	inline void set_id(string i) { this->id = i; }
	inline void set_destination(string i) { this->destination= i; }
	inline void set_date_start(string i) { this->date_start =i; }
	inline void set_date_end(string i) {  this->date_end=i; }
	inline void set_type(OfferType i) { this->type = i; }
	inline int get_price()const { return this->price; }
	inline string get_id()const { return this->id; }
	inline string get_destination()const { return this->destination; }
	inline string get_date_start()const { return this->date_start; }
	inline string get_date_end()const { return this->date_end; }
	inline OfferType get_type()const { return this->type; }
	Offer(string id, unsigned int price1, string destination1, string date_start1, string date_end1, OfferType type);
	Offer();
	friend ostream& operator<<(ostream& s, const Offer& of);


private:
	string id;
	unsigned int price;
	string destination;
	string date_start;
	string date_end;

	OfferType type;



};

