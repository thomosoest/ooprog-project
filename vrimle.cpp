#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "funksjoner.h"
#include "steder.h"
#include "sted.h"
#include "vrimle.h"
#include "ListTool2B.h"
#include "sone.h"




using namespace std;


Vrimle::Vrimle(char *t) : Sone(t) {

	cout << "Vrimle constructor";
}

void Vrimle::display() {
	//Sone::display();
	cout << "Vrimledisplay";
}


#endif