#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "funksjoner.h"
#include "steder.h"
#include "sted.h"
#include "stoler.h"
#include "ListTool2B.h"
#include "sone.h"


using namespace std;


Stoler::Stoler(char *t) : Sone(t) {

	rad = lesTall("Hvor mange rader: ", 1, RAD);		//Leser inn hvor mange rader
	rekke = lesTall("Hvor mange rekker: ", 1, REKKE);	//Lesre inn hvor mange rekker

	sete[RAD][REKKE] = sete[rad][rekke];				//setter innlest rader og rekker til arrayen

	type = 'S'; //Setter type som 'S'
}

void Stoler::display() {
	
	Sone::display();									//Kaller paa sone sin displayfunksjon

	for (int i = 1; i <= rad; i++) {					//Displayer rader og rekker 
		cout << "\n0 ";
		for (int j = 1; j <= rekke; j++) {
			cout << " 0 ";
		}
	}
}

Stoler::Stoler(Stoler & s) : Sone((Sone*)&s) { //kopiert fra frode
	//int i, j;

	rad = s.rad;
	rekke = s.rekke;

	/*
	billett = new int*[rad + 1];
	for (i = 1; i <= rad; i++)
		billett[i] = new int[rekke + 1];

	for (i = 1; i <= rad; i++)
		for (j = 1; j <= rekke; j++)
			billett[i][j] = 0;
			*/
}

char Stoler::hentType() { //Virituell funksjon som returnerer type objekt Stoler/Vrimle
	return type;
}

void Stoler::skrivTilfil(ofstream & utfil) {
	utfil << "S" << "\n";		//'S' for stolerobjekt	
	utfil << text << "\n"; 		//Navn paa soneobjekt
	utfil << pris << "\n";		//Pris
	utfil << antBill << "\n";	//Antall billetter
	utfil << rad << "\n";		//Rad
	utfil << rekke << "\n";		//Rekke
}

Stoler::Stoler(char t[], ifstream & innfil) : Sone(t, innfil) { //Sender navn opp til sone
	innfil >> pris;				//Pris
	innfil >> antBill;			//Antall billetter
	innfil >> rad;				//Rad
	innfil >> rekke;			//Rekke
}
#endif