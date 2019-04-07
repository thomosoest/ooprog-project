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
	rekke = lesTall("Hvor mange rekker: ", 1, REKKE);	//Leser inn hvor mange rekker
	antBill = rad * rekke;

	billetter[RAD][REKKE] = billetter[rad][rekke];				//setter innlest rader og rekker til arrayen

	type = 'S';										    //Setter type som 'S'
}

void Stoler::display() {
	
	Sone::display();									//Kaller paa sone sin displayfunksjon

	int i = 1, j = 1;
	for (i = 1; i <= rad; i++) {					//Displayer rader og rekker 
		cout << "\n " << billetter[i][j];
		for (j = 1; j <= rekke; j++) {
			cout << " " << billetter[i][j] << " ";
		}
	}
}

Stoler::Stoler(Stoler & s) : Sone((Sone*)&s) { //kopiert fra frode
	int i, j;

	rad = s.rad;
	rekke = s.rekke;

	for (i = 1; i <= rad; i++)
		for (j = 1; j <= rekke; j++)
			billetter[i][j] = 0;
			

	type = 'S';
}

char Stoler::hentType() { //Virituell funksjon som returnerer type objekt Stoler/Vrimle
	return type;
}

void Stoler::skrivTilfil(ofstream & utfil) {
	utfil << "S" << "\n";		//'S' for stolerobjekt	
	utfil << text << "\n"; 		//Navn paa soneobjekt
	utfil << pris << "\n";		//Pris
	utfil << antSolgt << "\n";	//Antall billetter solgt
	utfil << antBill << "\n";	//Antall billetter
	utfil << rad << "\n";		//Rad
	utfil << rekke << "\n";		//Rekke

	int i = 1, j = 1;
	for (i = 1; i <= rad; i++) {
		utfil << "\n " << billetter[i][j];
		for (j = 1; j <= rekke; j++) {
			utfil << " " << billetter[i][j] << " ";
		}
	}

}

Stoler::Stoler(char t[], ifstream & innfil) : Sone(t, innfil) { //Sender navn opp til sone
	innfil >> pris;				//Pris
	innfil >> antSolgt;			//Antall billetter solgt
	innfil >> antBill;			//Antall billetter
	innfil >> rad;				//Rad
	innfil >> rekke;			//Rekke
	type = 'S';

	int i = 1, j = 1;
	for (i = 1; i <= rad; i++) {		//For lokke som leser inn kundenr paa plassene
		innfil >> billetter[i][j];		
		for (j = 1; j <= rekke; j++) {
			innfil >> billetter[i][j];
		}
	}
}


int Stoler::hentantbill() {				//returnerer antall billetter som kan kjopes
	return antBill;
}
void Stoler::kjop(int kjop, int knr) {	//Kjop funksjon for stoler
	int telle = 0, kjoprad, kjoprekke;
	for (int i = 1; i <= kjop; i++) {	//looper til antall billeter kunden onsker aa kjope
		do {
			kjoprad = lesTall("Hvilken rad onsker du?", 1, rad);		
			kjoprekke = lesTall("Hvilken rekke onsker du?", 1, rekke);
			if (billetter[kjoprad][kjoprekke] != 0)								
				cout << "\n\tPlassen er opptatt! Skriv inn paa nytt!\n\n";
		} while (billetter[kjoprad][kjoprekke] != 0);				//Loopes til bruker taster inn plass hvor det er ledig
			billetter[kjoprad][kjoprekke] = knr;					//medsendt kundenr blir satt paa plassen
			cout << "\nPlassen er kjopt!\n";
			telle++;												//Teller omm hvor mange billetter kunden har kjopt
	}
	antSolgt += telle;
	antBill -= telle; 

}
void Stoler::billettTilFil(ofstream & utfil, int a) {	//funksjon for "billeter.dta" faar inn "a" antall billeter kunden har kjopt
	
	utfil << "\nNavn paa sone: " << text << ".";
	utfil << "\nDu har kjopt " << a << " billetter til kr. " << pris << " per stykk.";
	utfil << "\nTotalsum er paa kroner: " << a * pris << ".";
}
#endif