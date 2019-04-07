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
	
	
	for (int i = 1; i <= antBill; i++)
		billetter[i] = 0; 
		
	type = 'V';
}

char Vrimle::hentType() { //Virituell funksjon som returnerer type objekt Stoler/Vrimle
	return type;
}
void Vrimle::skrivTilfil(ofstream & utfil) {
	utfil << "V" << "\n";		//'V' for Vrimle
	utfil << text << "\n";		//Sonenavn
	utfil << pris << "\n";		//Pris
	utfil << antSolgt << "\n";	//Antall solgt
	utfil << antBill << "\n";	//Antall billetter

	for (int i = 1; i <= antSolgt; i++) {
		utfil << billetter[i] << "\n";
		}
	
}
Vrimle::Vrimle(char t[], ifstream & innfil) : Sone(t, innfil) { //Sender navn opp til sone
	innfil >> pris;				//Pris
	innfil >> antSolgt;			//Antall solgt
	innfil >> antBill;			//Antall billetter
	type = 'V';
	int knr;
	for (int i = 1; i <= antSolgt; i++) {
		innfil >> knr;
		billetter[i] = knr;
	}
}
int Vrimle::hentantbill() {					//Returnerer antall billetter som kan kjopes
	return antBill;
}

void Vrimle::kjop(int kjop, int knr) {		//Kjop funksjon for stoler
	int i;
	for (i = 1; i <= kjop; i++)				//looper til antall billeter kunden onsker aa kjope
		billetter[antSolgt + i] = knr;		//plass i arrayen blir satt til kundenr.
	
	antSolgt += kjop;
	antBill -= kjop;
}
void Vrimle::billettTilFil(ofstream & utfil, int a) { //funksjon for "billeter.dta" faar inn "a" antall billeter kunden har kjopt

	utfil << "\nNavn paa sone: " << text << ".";
	utfil << "\nDu har kjopt " << a << " billetter til kr. " << pris << " per stykk.";
	utfil << "\nTotalsum er paa kroner: " << a * pris << ".";
}


#endif