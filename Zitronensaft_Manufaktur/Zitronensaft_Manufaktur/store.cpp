#include "pch.h"
#include "Store.h"
#include "Zitronenpresse.h"


Store::Store()
{
}


Store::~Store()
{
}

void Store::menu()
{

	char todo = 'J';

	while (todo == 'J') {

		cout << "Willkommen im Shop. Was moechten Sie bestellen?" << endl;
		cout << "1. Zitronen (10er Pack)" << endl;

		cin >> selector;

		switch (selector) {
		case 1: {
			
			this->getZitronen(); //random zitronen erstellen
			this->showCart(); //Warenkorb print

			cout << "Wollen Sie weiter einkaufen (J) oder die Zitronen Pressen (P): ";
			cin >> todo;

			if (todo == 'P' || todo == 'p') {
				Zitronenpresse *Presse = Zitronenpresse::getInstance();
#
				//zitronen in die zitronenpresse übertragen
				for (Zitrone *zitrone : this->lager) {

					Presse->zitronen.push_back(zitrone);

				}

				lager.clear(); //lager leeren

				Presse->Press(); //name ist programm
				return;
			}

		}break;
		default: {
			cout << "Falsche Eingabe. Versuchen Sie es nochmal." << endl;
		}break;
		}
	}
}

void Store::showCart()
{
	cout << "Folgendes ist im Einkaufswagen:" << endl;
	
	for (Zitrone* item : this->lager) {

		cout << "Zitrone Groesse " << item->getSize() << " mit Saftinhalt: " << item->getML() << endl;

	}
}

void Store::getZitronen()
{
	srand(time(NULL));

	for (unsigned int i = 0; i < 10; i++) {

		int size = rand() % 5;

		switch (size) {
		case 0: {
			Zitrone* neue = new Zitrone1();
			this->lager.push_back(neue);
		}break;
		case 1: {
			Zitrone* neue = new Zitrone2();
			this->lager.push_back(neue);
		}break;
		case 2: {
			Zitrone* neue = new Zitrone3();
			this->lager.push_back(neue);
		}break;
		case 3: {
			Zitrone* neue = new Zitrone4();
			this->lager.push_back(neue);
		}break;
		case 4: {
			Zitrone* neue = new Zitrone5();
			this->lager.push_back(neue);
		}break;
		}

	}
}

