#pragma once
#include <vector>
#include "Zitrone.h"

using namespace std;
class Zitronenpresse
{
public:
	
	~Zitronenpresse();
	static Zitronenpresse *getInstance(Store *store);
	void Press(Store* store);

private:
	Zitronenpresse(Store *store);
	static Zitronenpresse *INSTANCE;
	static int PRESSVORGAENGE;
	static int SAFTVOLUMEN;
	Store *store;
	
};

