#include "Offer.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& s, const Offer& of)
{
	s << "id:";
	s << of.id;
	s << " price:";
	s << of.price;
	s << " destination:";
	s << of.destination;
	s << " start date:";
		s << of.date_start;
		s << " end date:";
		s << of.date_end;
		s << " type:";
		s << of.type;
		return s;
}

Offer::Offer(string id1, unsigned int price1, string destination1, string date_start1, string date_end1, OfferType type1)
{
	id = id1;
	this->destination = destination1;
	this->price = price1;
	this->date_start = date_start1;
	this->date_end = date_end1;
	this->type = type1;
}

Offer::Offer()
{
}
