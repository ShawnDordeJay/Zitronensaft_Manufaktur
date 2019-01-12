#include "pch.h"
#include "Zitronenpresse.h"
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

void Zitronenpresse::Press(vector <Zitrone*> zitronen)
{
	int stk, gesamtml = 0;

	cout << "Wie viele Zitronen moechten Sie pressen?" << endl;
	cin >> stk;

	for (unsigned int i = 0; i < stk; i++) {

		gesamtml += zitronen[i]->getML;

	}

	try {
		if (gesamtml >= 150) {
			cout << "Zitronen werden gepresst. Bitte warten..." << endl;

			for (unsigned int i = 0; i < stk; i++) {
				this->PRESSVORGAENGE++;
				this->SAFTVOLUMEN += zitronen[i]->getML;
			}

			zitronen.erase(zitronen.begin(), zitronen.begin() + stk);

			cout << "Erledigt" << endl;
		}
		else {
			throw 
		}
	}
	catch{

	}
}

Zitronenpresse *Zitronenpresse::INSTANCE = 0;

int Zitronenpresse::PRESSVORGAENGE = 0;
int Zitronenpresse::SAFTVOLUMEN = 0;
