#include <iostream>
#include "funksjoner.h"
#include "kunder.h"
#include "kunde.h"
#include "const.h"
#include <fstream>


using namespace std;


Kunder::Kunder()
{
	sisteKunde = 1;
	kundeListe = new List(Sorted);
}


void Kunder::nyKunde()
{
	cout << "\nKunde id: " << sisteKunde << endl;
	kundeListe->add(new Kunde(sisteKunde));
	++sisteKunde;
}

void Kunder::displayKunde()
{
	char kommando = 'E'; int n = 0; 

	cout << "A: Alle data om alle kunder\n"
		 << "I: Alle data om en kunde via ID\n" 
		 << "N: Alle data om alle kunder med gitt navn\n";

	kommando = les();

	switch (kommando) {
	case 'A': kundeListe->displayList();  break;
	case 'I':		{ 
		cout << "Hvilken kunde?(ID-nummer):  ";
		cin >> n;
		kundeListe->inList(n);

		if (kundeListe->inList(n)) {
			cout << "\nKunde funnet!\n";
			kundeListe->displayElement(n); break;
		}
		else {
			cout << "\nkunde ikke funnet\n";
		}
	}

	case 'N':		{
		int i = 1;  bool enFunnet = false, funnet = false;
		char buf[STRLEN];
		lesTekst("Kundens navn: ", buf, STRLEN);

		while (i <= sisteKunde) {
			funnet = false;
			Kunde* tempKunde;
			tempKunde = (Kunde*)kundeListe->remove(i);
			if (tempKunde) {
				funnet = tempKunde->riktigNavn(buf);
				kundeListe->add(tempKunde);
			}
			if (funnet) {
				kundeListe->displayElement(i);
				enFunnet = true;
			}
			i++;
		}
		if (!enFunnet) cout << ("\nKunde ikke funnet!\n");
	}	break; 

	default: cout << "\n Feil input\n"; break;
	}



	
}

void Kunder::endreKunde() {
	int i;
	i = lesTall("Hvilken kunde vil du endre p�? ", 1, 10000);
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
		kundeListe->displayList();
		cin >> i;
		Kunde* tempKunde;
		tempKunde = (Kunde*)kundeListe->destroy(i);		//Fjerner kunden fra lista og legger den i tempKunde
		cout << "\nkunden er slettet.\n";
	}
	else
	{
		cout << "\nIngen kunde har blitt slettet\n";
	}
}


void Kunder::meny()	{
	char kommando = 'E'; 

	kommando = les();
	switch (kommando) {
	case 'D': displayKunde(); break;
	case 'N': nyKunde(); break;
	case 'E': endreKunde(); break;
	case 'S': slettKunde(); break;
	}

}

void Kunder::lesFil() {
		ifstream innfil("KUNDER.DTA");
		int nr;
		int antkunder;

		if (innfil) {
			innfil >> antkunder; innfil.ignore();
			nr = (kundeListe->noOfElements()) + 1;
			for (int i = 1; i <= antkunder; i++) {
				kundeListe->add(new Kunde(nr, innfil));
				nr++;
			}
		}

		else cout << "\n\t\tFinner ikke fil med kunder: KUNDER.DTA\n\n";

}


void Kunder::skrivFil() {

	ofstream utfil("KUNDER1.DTA");
	Kunde * temp;

	utfil << (kundeListe->noOfElements()) << "\n";

	for (int i = 1; i <= kundeListe->noOfElements(); i++) {

		temp = (Kunde*)kundeListe->removeNo(i);
		temp->skrivFil(utfil);
		kundeListe->add(temp);
	}


}