#pragma once
#include <vector>
#include "Zitrone.h"

using namespace std;
class Zitronenpresse
{
public:
	
	~Zitronenpresse();
	static Zitronenpresse *getInstance();
	void Press();
	void setStore(Store *store);

private:
	Zitronenpresse();
	static Zitronenpresse *INSTANCE;
	static int PRESSVORGAENGE;
	static int SAFTVOLUMEN;
	vector <Zitrone*> zitronen;
	Store *store;
	
};

