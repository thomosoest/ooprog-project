#include <iostream>
#include "funksjoner.h"


#include "kunder.h"
#include "kunde.h"



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
	int funnet = 0;


	cout << "A: Alle data om alle kunder" << endl
		<< "I: Alle data om en kunde via ID" << endl
		<< "N: Alle data om alle kunder med gitt navn" << endl;


	kommando = les();

	switch (kommando)

	{
	case 'A': kundeListe->displayList();  break;
	case 'N': {
		
		while (funnet = false){		
		cout << "Hvilken kunde(ID-nummer):  " << endl;
		cin >> n; 
		funnet = (kundeListe->inList(n));
		}

		kundeListe->displayElement(n); break;

	}

	default:
		break;
	}



	
}


void Kunder::meny()
{
	char kommando = 'E'; 

	kommando = les();

	switch (kommando) {

	case 'D': displayKunde(); break;
	case 'N': nyKunde() ; break;
	case 'E':cout << "Venne funksjonen skal endre en kunde" << endl; break;
	case 'S':cout << "Denne funksjonen skal slette en kunde" << endl; break;

	case 'A':cout << "Valg A" << endl; break;
	case 'B':cout << "Valg B" << endl; break;
	case 'C':cout << "Valg C" << endl; break;

	}

}