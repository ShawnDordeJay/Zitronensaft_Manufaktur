#pragma once
#include "Zitrone.h"
#include "Zitrone1.h"
#include "Zitrone2.h"
#include "Zitrone3.h"
#include "Zitrone4.h"
#include "Zitrone5.h"
#include "Zitronenpresse.h"
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;
class Store
{
public:
	Store();
	~Store();

	vector <Zitrone*> lager;
	void menu();
	

private:
	int selector;
	void getZitronen();//fügt verschiedene Größen von Zitronen zum lager
	void showCart(); //anzeigen des Inhalts im Warenkorb
};

