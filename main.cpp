// Inkluderte bibliotek
#include <iostream>
// Inkluderte h.filer
#include "funksjoner.h"	
#include "kunder.h"
#include "steder.h"
#include "arrangementer.h"


using namespace std;

// Funksjons deklarasjoner
void skrivMeny();

// Globale variable:

Kunder kunder;
Steder steder;
Arrangementer arrangementer;

int main()
{
	char kommando = 'E';

	kunder.lesFil();

	arrangementer.lesFil();
	skrivMeny();								// Skriver meny

	
	do {
		cout << "\nSkriv inn kommando: ";
		kommando = les();								// Les funksjonen får og uppcaser kommandoen
	 

switch (kommando) {

		case 'O':
		case 'S': steder.meny(kommando); break;			//Sender deg til steder-menyen
		case 'K': kunder.meny(); break;					//Sender deg til kunde-menyen
		case 'A': arrangementer.meny(); break;			//Sender deg til arrangements menyen
		default: skrivMeny(); break;
		}	
	} while (kommando != 'Q');

	kunder.skrivFil();
	//steder.skrivTilFil();
	return 0;
	}


void skrivMeny() {
   cout << "\t\nHovedmenyen: \n" 
	   << "K D: Displayer kunde data \n"
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



