#include <iostream>
#include "funksjoner.h"
#include "kunder.h"
#include "kunde.h"
#include "const.h"


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

	char kommando = 'E';
	int n = 0;
	int funnet = 1;


	cout << "A: Alle data om alle kunder" << endl
		 << "I: Alle data om en kunde via ID" << endl
		 << "N: Alle data om alle kunder med gitt navn" << endl;


	kommando = les();

	switch (kommando) {
	case 'A': kundeListe->displayList();  break;
	case 'I':  cout << "Hvilken kunde?(ID-nummer):  ";
		cin >> n;
		
		kundeListe->inList(n);


		if (kundeListe->inList(n))	{
			cout << endl << "Kunde funnet!" << endl;
			kundeListe->displayElement(n); break;	
		}
		else{
			cout << endl << "kunde ikke funnet" << endl;
		}

	case 'N':		
		
	{
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

		if (!enFunnet) cout << ("Kunde ikke funnet!");
	}
		
		
		break; 

	default: cout << "**********" << endl;	break;
	}



	
}

void Kunder::endreKunde() {

	//int i;




}



void Kunder::meny()	{
	char kommando = 'E'; 

	kommando = les();

	switch (kommando) {

	case 'D': displayKunde(); break;
	case 'N': nyKunde(); break;
	case 'E': endreKunde(); break;
	case 'S':cout << "Denne funksjonen skal slette en kunde" << endl; break;

	}

}