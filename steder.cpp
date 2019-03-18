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
	case 'D': displaySted(); break;
	case 'N': nyttSted(); break;
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

