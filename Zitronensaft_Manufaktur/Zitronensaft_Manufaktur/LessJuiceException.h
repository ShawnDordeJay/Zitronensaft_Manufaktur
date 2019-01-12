#pragma once
#include <exception>


using namespace std;

class LessJuiceExeption : public exception {

public:

	virtual const char* what() const throw() {

		char selection;

		cout << "Saftmenge kleiner als 150ml." << endl;
		cout << "Wenn Sie noch mehr vom Lager pressen wollen, druecken Sie P. ";
		cout << "Wenn Sie mehr Zitronen kaufen wollen, druecken Sie Z.";
		cin >> selection;

		switch (selection) {
		case 'P': {
			Zitronenpresse *presse = Zitronenpresse::getInstance();
			presse->Press();
		}
		}
	}

};
