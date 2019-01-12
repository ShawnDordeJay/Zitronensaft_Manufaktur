#pragma once
#include <vector>
#include "Zitrone.h"

using namespace std;
class Zitronenpresse
{
public:
	
	~Zitronenpresse();
	static Zitronenpresse *getInstance();
	void Press(vector <Zitrone*> zitronen);

private:
	Zitronenpresse();
	static Zitronenpresse *INSTANCE;
	static int PRESSVORGAENGE;
	static int SAFTVOLUMEN;
	
};

