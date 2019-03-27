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
		if (stedListe->inList(nvn)) { cout << "Stedsnavn finnes allerede"; }
	} while (strlen(nvn) == 0 || stedListe->inList(nvn) == true); //Looper om ugyldig stedsnavn
	
	
	if (stedListe->inList(nvn)) { cout << "finnes"; }

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
	
	
	
	do {
		cout << "Vil du opprette: \n\t(E)tt helt nytt oppsett \n\t(K)opiere oppsett fra annet og endre paa\n";
		cin >> svar;
		toupper(svar);
	} while (svar != 'E' && svar != 'K');
	

	peker = (Sted*)stedListe->remove(arr);
	int ops = peker->hentNrOppsett(); //Henter tall paa siste oppsett brukt

	if (svar == 'E') {
		if (ops <= 4) {
			ops = peker->lagNyttOppsettListe(); //lager ett nytt oppsett

			cout << "\nOppsett nummer: " << ops;
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
		
	}
	else if (svar == 'K'){

		
		peker->hentNrOppsett(); //Oppdaterer sisteBrukt av oppsett

		char * frasted;
		int oppsettnr;
		
		char buff[STRLEN];
		lesTekst("Hvilket sted vil du kopiere fra: ", buff, STRLEN);
		frasted = new char[strlen(buff) + 1]; strcpy(frasted, buff);

		cout << "Hvilket oppsett vil du kopiere?";
		cin >> oppsettnr;
	
		peker->nyttOppsett(kopier(frasted, oppsettnr));
		
		peker->hentNrOppsett();
	}
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

	svar = lesTall("Hvilket stoloppsett vil du se: ", 1, peker->hentNrOppsett());
	peker->displayOppsett(svar); //Kaller paa displayfunksjon i sted
	
	stedListe->add(peker);						//legger sted tilbake i listen
}

List* Steder::kopier(char* nvn, int nr) { //Kopiert fra frode
	List* liste = NULL;
	Sted* sted;

	if ((sted = (Sted*)stedListe->remove(nvn))) {
		liste = sted->kopier(nr);
		stedListe->add(sted);
	}
	return liste;
}

bool Steder::finnesSted(char * nvn) {
 return stedListe->inList(nvn);
}

#endif