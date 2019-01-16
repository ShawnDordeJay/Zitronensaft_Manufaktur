#pragma once
#include <exception>
#include "store.h"


using namespace std;

class LessJuiceExeption : public exception {

public:

	LessJuiceExeption(Store *store) {
		this->store = store;
	}

	virtual const char* what() const throw() {

		char selection;

		cout << "Saftmenge kleiner als 150ml." << endl;
		cout << "Wenn Sie noch mehr vom Lager pressen wollen, druecken Sie P. ";
		cout << "Wenn Sie mehr Zitronen kaufen wollen, druecken Sie Z.";
		
		do {
			cin >> selection;
			selection = toupper(selection); //selection in grossbuchstaben, leichter zum arbeiten danach
			
			if ((selection != 'P') && (selection != 'Z')) {
				cout << "nice try, try again" << endl;
			}
		} while ((selection != 'P') && (selection != 'Z'));

		
		if (selection == 'P' || selection == 'Z') {
			switch (selection) {
			case 'P': {
				Zitronenpresse *presse = Zitronenpresse::getInstance();
				presse->Press();
				return "";
			} break;
			case 'Z': {
				this->store->menu();
				return "";
			}break;
			}
		}
	}

private:
	Store* store;


};
