#include "pch.h"
#include "Zitronenpresse.h"
#include "LessJuiceException.h"
#include <iostream>


Zitronenpresse::Zitronenpresse()
{
}


Zitronenpresse::~Zitronenpresse()
{
}

Zitronenpresse * Zitronenpresse::getInstance()
{

	if (INSTANCE == 0) {

		INSTANCE = new Zitronenpresse();
	}

	return INSTANCE;
}

void Zitronenpresse::Press()
{
	int stk, gesamtml = 0;

	cout << "Wie viele Zitronen moechten Sie pressen?" << endl;
	cin >> stk;

	//check ob eingegebene stk zahl größer als die zitronenanzahl
	while (stk > this->zitronen.size()) {
		cout << "Es sind nur " << this->zitronen.size() << " vorhanden. Bitte neu eingeben: " << endl;
		cin >> stk;
	}

	//check ob 150 ml erreicht werden
	for (unsigned int i = 0; i < stk; i++) {

		gesamtml += this->zitronen[i]->getML();

	}

	try {
		if (gesamtml >= 150) {
			cout << "Zitronen werden gepresst. Bitte warten..." << endl;

			for (unsigned int i = 0; i < stk; i++) {
				this->PRESSVORGAENGE++;
				this->SAFTVOLUMEN += this->zitronen[i]->getML();
			}

			this->zitronen.erase(this->zitronen.begin(), this->zitronen.begin() + stk);

			cout << "Erledigt" << endl;
		}
		else {
			throw LessJuiceExeption(this->store);
		}
	}
	catch(LessJuiceExeption &ex){

		ex.what();

	}
}

void Zitronenpresse::setStore(Store * store)
{
	this->store = store;
}

Zitronenpresse *Zitronenpresse::INSTANCE = 0;

int Zitronenpresse::PRESSVORGAENGE = 0;
int Zitronenpresse::SAFTVOLUMEN = 0;
