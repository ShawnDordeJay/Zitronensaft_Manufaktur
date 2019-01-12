// 
//

#include "pch.h"
#include <iostream>
#include "store.h"
#include "Zitronenpresse.h"

int main()
{
	//Shop-Objekt erstellen
	store *Zitronenfachhandel = new store();
	Zitronenfachhandel->menu();

	Zitronenpresse *Presse = Zitronenpresse::getInstance();
	Presse->Press(Zitronenfachhandel->lager);


}

