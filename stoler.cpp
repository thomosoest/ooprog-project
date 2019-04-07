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

	/*for (int i = 1; i <= rad; i++) {					//Displayer rader og rekker 
		cout << "\n0 ";
		for (int j = 1; j <= rekke; j++) {
			cout << " 0 ";
		}
	}
	*/
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
	for (i = 1; i <= rad; i++) {
		innfil >> billetter[i][j];
		for (j = 1; j <= rekke; j++) {
			innfil >> billetter[i][j];
		}
	}
}


int Stoler::hentantbill() {
	return antBill;
}
void Stoler::kjop(int kjop, int knr, char * nvn) {
	int telle = 0, kjoprad, kjoprekke;
	for (int i = 1; i <= kjop; i++) {
		kjoprad = lesTall("Hvilken rad onsker du?", 1, rad);
		kjoprekke = lesTall("Hvilken rekke onsker du?", 1, rekke);
		if (billetter[kjoprad][kjoprekke] == 0) {
			billetter[kjoprad][kjoprekke] = knr;
			cout << "\nPlassen er kjopt!\n";
			telle++;
		}
		else cout << "Plassen er opptatt!";
	}
	antSolgt += telle;
	antBill -= telle;
}

#endif