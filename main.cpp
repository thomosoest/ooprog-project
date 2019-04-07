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
	// an array with 5 rows and 2 columns.
	int a[5][2] = { { 0,0 },{ 1,2 },{ 2,4 },{ 3,6 },{ 4,8 } };

	// output each array element's value                      
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++) {

			cout << "a[" << i << "][" << j << "]: ";
			cout << a[i][j] << endl;
		}




	char kommando = 'E';

	kunder.lesFil();
	steder.lesFraFil();
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
	steder.skrivTilFil();
	arrangementer.skrivFil();

	return 0;
	}


void skrivMeny() {				//Hovedmenyens funksjon
   cout << "\t\nHovedmenyen: \n" 
	    << "K D: Displayer kunde data \n"
		<< "K N: Legger til ny kunde\n"
		<< "K E: Endrer data for en kunde\n"
	    << "K S: Sletter en kunde\n"
		<< "\nS D: Displayer data anngaaende sted \n"
		<< "S N: Legger til nytt Sted \n"
		<< "\nO D: Displayer Oppsett\n"
		<< "O N: Nytt Oppsett\n"
		<< "O E: Endre Oppsett\n"
		<< "\nA D: Display arrangement\n"
		<< "A N: Nytt Arrangement\n"
		<< "A S: Slett arrangement\n"
		<< "A K: Kjøp Billett\n";
}



