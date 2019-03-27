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

		type = 'V'; //Setter type som 'V'
}

void Vrimle::display() {
	Sone::display(); 
}
Vrimle::Vrimle(Vrimle & v) : Sone((Sone*)&v) { //Kopiert fra frode
	
	/*
	billett = new int[antTotalt + 1];
	for (int i = 1; i <= antTotalt; i++)
		billett[i] = 0;
		*/
	type = 'V';
}

char Vrimle::hentType() {
	return type;
}

#endif