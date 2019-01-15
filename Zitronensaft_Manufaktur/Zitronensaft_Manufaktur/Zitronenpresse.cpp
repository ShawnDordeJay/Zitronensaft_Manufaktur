#include "pch.h"
#include "Zitronenpresse.h"
#include "LessJuiceException.h"
#include <iostream>


Zitronenpresse::Zitronenpresse(Store *store)
{
	this->store = store;
}


Zitronenpresse::~Zitronenpresse()
{
}

Zitronenpresse * Zitronenpresse::getInstance(Store *store)
{

	if (INSTANCE == 0) {

		INSTANCE = new Zitronenpresse(store);
	}

	return INSTANCE;
}

void Zitronenpresse::Press(Store* store)
{
	int stk, gesamtml = 0;

	cout << "Wie viele Zitronen moechten Sie pressen?" << endl;
	cin >> stk;

	for (unsigned int i = 0; i < stk; i++) {

		gesamtml += store->lager[i]->getML();

	}

	try {
		if (gesamtml >= 150) {
			cout << "Zitronen werden gepresst. Bitte warten..." << endl;

			for (unsigned int i = 0; i < stk; i++) {
				this->PRESSVORGAENGE++;
				this->SAFTVOLUMEN += store->lager[i]->getML();
			}

			store->lager.erase(store->lager.begin(), store->lager.begin() + stk);

			cout << "Erledigt" << endl;
		}
		else {
			throw LessJuiceExeption(Store* store);
		}
	}
	catch{



	}
}

Zitronenpresse *Zitronenpresse::INSTANCE = 0;

int Zitronenpresse::PRESSVORGAENGE = 0;
int Zitronenpresse::SAFTVOLUMEN = 0;
