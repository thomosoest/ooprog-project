#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cctype>
#include "funksjoner.h"
#include "steder.h"
#include "sted.h"
#include "ListTool2B.h"



using namespace std;


Steder::Steder()
{
	stedListe = new List(Sorted);
}


void Steder::meny(char valg)
{
	


	if (valg == 'S') {
		char kommando = les();
		switch (kommando) {
		case 'D': displaySted(); break;
		case 'N': nyttSted(); break;
		}
	}
	else if (valg == 'O') {
		
		char kommando = les();
		switch (kommando) {
		case 'N': nyttOppsett();
		case 'E': break;
		}
	}
	}



void Steder::nyttSted() {

	char nvn[STRLEN];

	do {
		lesTekst("Navn paa sted", nvn, STRLEN);
	} while (strlen(nvn) == 0); //Looper om trykker enter
	
	stedListe->add(new Sted(nvn));
}

void Steder::displaySted() {
	
	stedListe->displayList();
}

void lesFraFilSteder() {
	ifstream innfil ("STEDER.DTA");

	if (innfil) {

		

	}
	else cout << "STEDER.DTA ikke funnet";

	
}

void Steder::skrivTilFilSteder() {
	ofstream utfil ("STEDER.DTA");
	
	Sted * temp;
	
	for (int i = 1; i <= stedListe->noOfElements(); i++) {
		
		temp = (Sted*) stedListe->removeNo(i);
		temp->skrivTilFilSted(utfil);
		stedListe->add(temp);
	}
}

void Steder::nyttOppsett() {
	char  arr[STRLEN];
	Sted * peker;
	char svar;
	char buff[STRLEN];
	char * sonenavn;

	do {
		lesTekst("Stednavn: ", arr, STRLEN);
		if (stedListe->inList(arr) != true)
			cout << "Ugyldig stedsnavn";
	} while (stedListe->inList(arr) != true);

	/*do {
		cout << "Vil du opprette: \n\tN: (E)tt helt nytt oppsett \n\t(K)opiere oppsett fra annet og endre paa\n";
		cin >> svar;
		toupper(svar);
	} while (svar == 'A' || svar == 'K');
	
	switch (svar) {
	case 'K': break;
	case 'E': break;
	}
	*/


	


	peker = (Sted*)stedListe->remove(arr);
	if (peker == nullptr) cout << "Peker er nullptr\n";

	int ops = peker->hentOppsett();
	//Oppsett[i] = new list om ikke er laget liste fra for
	if (peker->hentOppsett() < 5) {
		do {
			
			lesTekst("Skriv inn sonenavn ('q' for aa avslutte): ", buff, STRLEN);
			sonenavn = new char[strlen(buff) + 1]; strcpy(sonenavn, buff);

			if (*sonenavn != 'q') {
				cout << "Sonetype: (S)toler / (V)rimle: ";
				cin >> svar;
				toupper(svar);

				if (svar == 'S') peker->nyStoler(sonenavn);
				else if (svar == 'V') peker->nyVrimle(sonenavn, ops);
			}

		} while (*sonenavn != 'q');
	}
	else cout << "For mange oppsett";
	stedListe->add(peker);

}
#endif