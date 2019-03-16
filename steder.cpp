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
	kommando = les();
}


void Steder::nyttSted() {

	char nvn[STRLEN];

	cout << "Navn paa sted"; cin.getline(nvn, STRLEN);

	stedListe->add(new Sted(nvn));
}

void Steder::displaySted() {
	
	stedListe->displayList();
}

