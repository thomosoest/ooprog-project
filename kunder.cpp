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




void Kunder::meny()
{
	char kommando = 'E';

	kommando = les();

	switch (kommando) {


		//case 'K':kunder.nyKunde(); break;
	case 'A':cout << "Valg A" << endl; break;
	case 'B':cout << "Valg B" << endl; break;
	case 'C':cout << "Valg C" << endl; break;




	}
	kommando = les();


}