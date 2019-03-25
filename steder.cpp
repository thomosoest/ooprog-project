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
	


	if (valg == 'S') {					//Om 'S' er skrevet
		char kommando = les();			//leser inn paafolgende char i konsollvindu
		switch (kommando) {				
		case 'D': displaySted(); break;	//kaller paa displayfunksjon for sted
		case 'N': nyttSted(); break;	//kaller paa funksjon for aa lage nytt sted
		}
	}
	else if (valg == 'O') {
		
		char kommando = les();
		switch (kommando) {
		case 'D': displayOppsett();	break;	//Kaller paa displayfunksjon for oppsett
		case 'N': nyttOppsett(); break;		//kaller paa funksjon for aa lage nytt oppsett
		case 'E': break;
		}
	}
	}



void Steder::nyttSted() { //Legger til ett nytt sted i stedListe

	char nvn[STRLEN];

	do {
		lesTekst("Navn paa sted", nvn, STRLEN);
	} while (strlen(nvn) == 0); //Looper om trykker enter
	
	stedListe->add(new Sted(nvn));
}

void Steder::displaySted() { //displayfunksjon for stedListe
	
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
	if (peker == nullptr) cout << "Peker er nullptr\n"; //for debug

	int ops = peker->hentOppsett(); //Lages liste inni her
	
	if (peker->hentOppsett() < 5) {
		do {
			
			lesTekst("Skriv inn sonenavn ('q' for aa avslutte): ", buff, STRLEN);
			sonenavn = new char[strlen(buff) + 1]; strcpy(sonenavn, buff);

			if (*sonenavn != 'q') {
				cout << "Sonetype: (S)toler / (V)rimle: ";
				cin >> svar;
				toupper(svar);

				if (svar == 'S') peker->nyStoler(sonenavn, ops);
				else if (svar == 'V') peker->nyVrimle(sonenavn, ops);
			}

		} while (*sonenavn != 'q');
	}
	else cout << "For mange oppsett";
	stedListe->add(peker);

}

void Steder::displayOppsett() { //Display funksjon for oppsett

	Sted * peker;		//for aa kalle paa funksjoner i Sted
	char arr[STRLEN];	//navn paa sted 
	int svar;			//hvilket oppsett som skal bli vist

	do {										//sjekker om gyldig stedsnavn
		lesTekst("Stednavn: ", arr, STRLEN);
		if (stedListe->inList(arr) != true)
			cout << "Ugyldig stedsnavn";
	} while (stedListe->inList(arr) != true);

	peker = (Sted*)stedListe->remove(arr);		//tar sted ut fra listen

	svar = lesTall("Hvilket stoloppsett vil du se: ", 1, 5);

	switch (svar) {
	case 1: peker->displayOppsett(1); break; 
	case 2: peker->displayOppsett(2); break;
	case 3: peker->displayOppsett(3); break; 
	case 4: peker->displayOppsett(4); break;
	case 5: peker->displayOppsett(5); break; 
	}
	stedListe->add(peker);						//legger sted tilbake i listen
}
#endif