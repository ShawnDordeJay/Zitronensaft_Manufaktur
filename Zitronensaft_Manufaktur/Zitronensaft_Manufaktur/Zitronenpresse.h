#pragma once
#include <vector>
#include "Zitrone.h"
#include "store.h"

using namespace std;
class Zitronenpresse
{
public:
	
	~Zitronenpresse();
	static Zitronenpresse *getInstance(); //singleton
	void Press(); //pressvorgang
	void setStore(Store *store);
	vector <Zitrone*> zitronen;

private:
	Zitronenpresse();
	static Zitronenpresse *INSTANCE;
	static int PRESSVORGAENGE;
	static int SAFTVOLUMEN;
	
	Store *store;
	
};

