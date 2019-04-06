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

	antBill = lesTall("Antall totalt", 1, 4000);   //Leser inn totalt antall billetter til salgs
	type = 'V';									   //Setter type som 'V'
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

char Vrimle::hentType() { //Virituell funksjon som returnerer type objekt Stoler/Vrimle
	return type;
}
void Vrimle::skrivTilfil(ofstream & utfil) {
	utfil << "V" << "\n";		//'V' for Vrimle
	utfil << text << "\n";		//Sonenavn
	utfil << pris << "\n";		//Pris
	utfil << antBill << "\n";	//Anall billetter
}
Vrimle::Vrimle(char t[], ifstream & innfil) : Sone(t, innfil) { //Sender navn opp til sone
	innfil >> pris;				//Pris
	innfil >> antBill;			//Antall billetter
}


int Vrimle::hentPlasser(int i) {
	return antBill;
}

#endif