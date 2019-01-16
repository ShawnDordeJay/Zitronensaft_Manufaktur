// 
//

#include "pch.h"
#include <iostream>
#include "store.h"
#include "Zitronenpresse.h"

int main()
{
	//Shop-Objekt erstellen
	Store *Zitronenfachhandel = new Store();
	
	Zitronenpresse *Presse = Zitronenpresse::getInstance();
	Presse->setStore(Zitronenfachhandel);

	Zitronenfachhandel->menu();
	Presse->Press();


}

