#include <iostream>
#include "funksjoner.h"
#include "kunder.h"
#include "kunde.h"
#include "const.h"
#include <fstream>


using namespace std;


Kunder::Kunder()
{
	sisteKunde = 1;						//Setter siste kunde til 1
	kundeListe = new List(Sorted);		//Lager ny sortert liste
}


void Kunder::nyKunde()					//Funksjon for aa legge til ny kunde
{
	cout << "\nKunde id: " << sisteKunde << endl;
	kundeListe->add(new Kunde(sisteKunde));	//Tar plass i memory og sender med nr til kunde sin constructor
	++sisteKunde;
}

void Kunder::displayKunde()				//Funksjon for aa skrive ut kundedataene
{
	char kommando = 'E'; int n = 0;

	cout << "A: Alle data om alle kunder\n"
		<< "I: Alle data om en kunde via ID\n"
		<< "N: Alle data om alle kunder med gitt navn\n";

	kommando = les();

	switch (kommando) {
	case 'A': kundeListe->displayList();  break;	//Skriver ut alle personlige data om alle kunder
	case 'I': {
		cout << "Hvilken kunde?(ID-nummer):  ";		//Skriver ut en kunde med gitt ID nummer
		cin >> n;
		kundeListe->inList(n);						//Viser alle alternativene

		if (kundeListe->inList(n)) {
			cout << "\nKunde funnet!\n";
			kundeListe->displayElement(n); break;	//Displayer den gitte kunden
		}
		else {
			cout << "\nkunde ikke funnet\n";		//Feilmelding
		}
	}

	case 'N': {
		int n = 0, t = 0;
		char buff[STRLEN];
		Kunde * tempKunde;

		lesTekst("Kundens navn: ", buff, STRLEN);

		for (int i = 1; i <= kundeListe->noOfElements(); i++) {	//Gaar igjennom alle kundene
			tempKunde = (Kunde*)kundeListe->removeNo(i);		//Tar ut
			if ((tempKunde->riktigNavn(buff))) {				//Sjekker via hjelpefunksjon i kunde.cpp
				tempKunde->display();				//Displayer kunden
				t++; 
			}			
			kundeListe->add(tempKunde);				//Legger tilbake
		} cout << "\n\t" << t << " Kunder funnet.\n";	break;
	}
	default: cout << "\n Feil input\n"; break;
	}
	

	
}

	


void Kunder::endreKunde() {
	int i;
	i = lesTall("Hvilken kunde vil du endre på? ", 1, 10000);
	Kunde* tempKunde;
	tempKunde = (Kunde*)kundeListe->removeNo(i);		//Fjerner kunden fra lista og legger den i tempKunde
	tempKunde->endreKunde();						//Sender til funksjon som forandrer dataene
	kundeListe->add(tempKunde);						//Leger den endrede kunden tilbake

}

void Kunder::slettKunde() {
	int i;				//Hjelpe variabler
	char kommando = 'E';
	
	cout << "\n Tast inn 'J' Hvis du vil slette en kunde? ";
	kommando = les();

	if (kommando == 'J')	{
		cout << "Hvilken kunde vil du slette?";
		kundeListe->displayList();						//Displayer alle potensielle 
		cin >> i;
		Kunde* tempKunde;
		tempKunde = (Kunde*)kundeListe->destroy(i);		//Sletter kunden fra lista 
		//Funksjon for aa fjerne billetter skal hit
		cout << "\nkunden er slettet.\n";
	}
	else
	{
		cout << "\nIngen kunde har blitt slettet\n";
	}
}


void Kunder::meny()	{		//Hovedmeny for kunder
	char kommando = 'E'; 

	kommando = les();
	switch (kommando) {
	case 'D': displayKunde(); break;	
	case 'N': nyKunde(); break;
	case 'E': endreKunde(); break;
	case 'S': slettKunde(); break;
	}

}

void Kunder::lesFil() {				//Leser fra fil
		ifstream innfil("KUNDER.DTA");
		int nr;
		int antkunder;

		if (innfil) {
			innfil >> antkunder; innfil.ignore();	//Leser inn hvor mange kunder som ligger paa filen
			nr = (kundeListe->noOfElements()) + 1;
			for (int i = 1; i <= antkunder; i++) {
				kundeListe->add(new Kunde(nr, innfil));	//Sender til fil konstruktor
				++nr;	++sisteKunde;					//Teller opp
			}
		}
		else cout << "\n\t\tFinner ikke fil med kunder: KUNDER.DTA\n\n";
}


void Kunder::skrivFil() {			//Skriver til fil

	ofstream utfil("KUNDER1.DTA");
	Kunde * temp;
	int n = kundeListe->noOfElements();

	utfil << (n) << "\n";

	for (int i = 1; i <= n; i++) {

		temp = (Kunde*)kundeListe->removeNo(i);	
		temp->skrivFil(utfil);			//Skriver ut for hver kunde
		kundeListe->add(temp);
	}
}