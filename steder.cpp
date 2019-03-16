#include <iostream>
#include "funksjoner.h"


#include "steder.h"
#include "sted.h"



using namespace std;


Steder::Steder()
{
	stedListe = new List(Sorted);
}


void Steder::meny()
{
	char kommando = 'E';

	kommando = les();

	switch (kommando) {
	//case 'D': stedListe->displayList; break;
	case 'A':cout << "Valg A" << endl; break;
	case 'B':cout << "Valg B" << endl; break;
	case 'C':cout << "Valg C" << endl; break;

	}
	kommando = les();
}
