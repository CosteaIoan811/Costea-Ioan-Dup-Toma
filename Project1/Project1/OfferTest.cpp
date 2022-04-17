#include "OfferTest.h"
#include <iostream>
#include <cassert>
void OfferTest::runAllTests()
{
	
		std::cout << "Offer test...";
		creationTest();
		EqualTest();
		settersGettersTest();
		std::cout << "Offer.h test end\n";
	
	
}

int OfferTest::creationTest()
{
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	assert(a.get_id() == "id1");
	assert(a.get_destination() == "Bucuresti");
	assert(a.get_price() == 3);
	assert(a.get_date_start() == "20.3.2022");
	assert(a.get_date_end() == "23.3.2022");
	assert(a.get_type() == CRUISE);



	return 0;
}
int OfferTest::EqualTest() {
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	Offer b = a;
	assert(b.get_id() == "id1");
	assert(b.get_destination() == "Bucuresti");
	assert(b.get_price() == 3);
	assert(b.get_date_start() == "20.3.2022");
	assert(b.get_date_end() == "23.3.2022");
	assert(b.get_type() == CRUISE);
	Offer c("0",0,"Aici","00.0.0000","00.0.0000", ALL_INCLUSIVE);
	c = a;
	assert(c.get_id() == "id1");
	assert(c.get_destination() == "Bucuresti");
	assert(c.get_price() == 3);
	assert(c.get_date_start() == "20.3.2022");
	assert(c.get_date_end() == "23.3.2022");
	assert(c.get_type() == CRUISE);
	return 0;
}

int OfferTest::settersGettersTest()
{
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	a.set_id("0");
	a.set_date_end("0");
	a.set_date_start("0");
	a.set_destination("0");
	a.set_price(0);
	a.set_type(ALL_INCLUSIVE);
	assert(a.get_id() == "0");
	assert(a.get_destination() == "0");
	assert(a.get_price() == 0);
	assert(a.get_date_start() == "0");
	assert(a.get_date_end() == "0");
	assert(a.get_type() == ALL_INCLUSIVE);

	return 0;
}
