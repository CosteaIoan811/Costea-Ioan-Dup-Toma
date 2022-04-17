#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArrayTest.h"
#include <cassert>
#include <iostream>
using namespace std;

#include "DynamicArray.h"
#include "Offer.h"
#include "FilteringCriteria.h"
void displayMenu() {
    string message = "Please select your option:\n";
    message += "A|a add an offer\n";
    message += "S|s show all offers\n";
    message += "P|p filter offers by price\n";
    message += "T|t filter offers by type\n";
    message += "B|b filter offers by type and price\n";
    message += "Q|q quit\n";

    cout << "\n\n" << message;

    bool running = true;
    char answer;

    DynamicArray da(1);
    Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
    Offer a1("id2", 42, "Alba", "20.3.2022", "25.3.2022", CITY_BREAK);
    da.append(a);
    da.append(a1);

    while (running)
    {
        cout << "\nOption: ";
        cin >> answer;
        if (answer == 'A' || answer == 'a') {
            string id1;
            unsigned int price1;
            string destination1; string date_start1; string date_end1; OfferType type1;
            
            cout << "id:" << endl; cin >> id1;
            cout << "price:" << endl; cin >> price1;
            cout << "destination:" << endl; cin>>destination1;
            cout << "date_start:" << endl; cin >> date_start1;
            cout << "date_end:" << endl; cin >> date_end1;
            int tip;
            cout << "Offertype (0.CITY_BREAK,1.CRUISE,2.ALL_INCLUSIVE):" << endl; cin >> tip;
            if (tip == 0)type1 = CITY_BREAK;
            if (tip == 1)type1 = CRUISE;
            if (tip == 2)type1 = ALL_INCLUSIVE;
            Offer offer(id1, price1, destination1, date_start1, date_end1, type1);
            da.append(offer);
        }
        else if (answer == 'S' || answer == 's') {
            cout << da;
        }
        else if (answer == 'P' || answer == 'p') {
            float price1;
            cout << "Price: ";
            cin >> price1;
            FilterPrice filterByPrice;
            filterByPrice.set_price(price1);
            DynamicArray da1 = filterByPrice.filter(da);
            cout << da1;
        }
        else if (answer == 'T' || answer == 't') {
            int tip1;
            cout << "Type";
            cin >> tip1;
            FilterType fil1(tip1);
           // fil1.set_type(tip1);
            DynamicArray da1 = fil1.filter(da);
            cout << da1;
        }
        else if (answer == 'B' || answer == 'b') {
            float price;
            cout << "Price: ";
            cin >> price;
            int tip;
            cout << "Type: ";
            cin >> tip;
            
            FilterTP ftp;
            ftp.setter(price, tip);
            DynamicArray da1 = ftp.filter(da);
            cout << da1;
        }
        else if (answer == 'Q' || answer == 'q') {
            cout << "Quitting...\n";
            running = false;
        }
        else {
            cout << "Invalid option\n";
        }
    }
}

int main() {
    displayMenu();
    /*
	Offer a("id1", 3, "Bucuresti", "20.3.2022", "23.3.2022", CRUISE);
	Offer a1("id2", 42, "Alba", "20.3.2022", "25.3.2022", CITY_BREAK);
	//cout << a;
	OfferTest::runAllTests();
	FilteringTest::runAllTests();
	DynamicArrayTest::runAllTests();

	DynamicArray arr;
	//arr.append("DynamicArray class");
	//arr.append("NOT");
	//arr.append("tested");
	arr.append(a);
	arr.append(a1);
	//cout << arr << endl;
	FilterPrice filterByPrice;
	//arr=filterByPrice.filter(arr);
	cout << arr;
	FilterType filterByType;
	//arr = filterByType.filter(arr);
	cout << arr;
	FilterTP fIlterByTP;
	arr = fIlterByTP.filter(arr);
	cout << arr;
	return 0;
    */
}