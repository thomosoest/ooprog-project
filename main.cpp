// Inkluderte bibliotek
#include <iostream>
// Inkluderte h.filer
#include "funksjoner.h"	
#include "kunder.h"
#include "steder.h"



using namespace std;

// Funksjons deklarasjoner
void skrivMeny();

// Globale variable:

Kunder kunder;
Steder steder;
//Arrangementer arrangementer;

int main()
{
	char kommando = 'E';

	kunder.lesFil();

	skrivMeny();								// Skriver meny
	kommando = les();							// Les funksjonen får og uppcaser kommandoen
	while (kommando != 'Q') {
		switch (kommando) {
		case 'S': steder.meny(); break;			//Sender deg til steder-menyen
		case 'K': kunder.meny(); break;			//Sender deg til kunde-menyen
		case 'A': //arrangement.meny();			////Sender deg til arrangements menyen
			break;

		default: skrivMeny(); break;
		}	
		kommando = les();
	}

	//skrivTilFil();

	return 0;
	}


void skrivMeny() {
	
	cout << "K D: Displayer kunde data \n"
		<< "K N: Legger til ny kunde\n"
		<< "K E: Endrer data for en kunde\n"
		<< "\nS D: Displayer data anngående sted \n"
		<< "S N: Legger til nytt Sted \n"
		<< "\nO D: Displayer Oppsett\n"
		<< "O N: Nytt Oppsett\n"
		<< "O E: Endre Oppsett\n"
		<< "\nA D: Display arrangement\n"
		<< "A N: Nytt Arrangement\n"
		<< "A S: Slett arrangement\n"
		<< "A K: Kjøp Billett\n";

}
