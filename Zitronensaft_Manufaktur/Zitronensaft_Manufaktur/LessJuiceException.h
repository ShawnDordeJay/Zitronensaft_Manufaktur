#pragma once
#include <exception>
#include "store.h"


using namespace std;

class LessJuiceExeption : public exception {

public:

	virtual const char* what() const throw() {

		return "Saftmenge kleiner als 150ml.";
		
	}
};
