
#include <iostream>
#include "funksjoner.h"	
#include "kunder.h"
#include "steder.h"

using namespace std;


void skrivMeny();



// Globale variable:

Kunder kunder;
Steder steder;
//Arrangementer arrangementer;





int main()
{

	//.lesFraFil();


	char kommando = 'E';

	skrivMeny();								// Skriver meny
	
	kommando = les();							// Les funksjonen f�r og uppcaser kommandoen


	while (kommando != 'Q') {
		switch (kommando) {
		


		case 'S': steder.meny(); break;
		case 'K': kunder.meny(); break;
		case 'A':cout << "Valg A" << endl; break;
		case 'B':cout << "Valg B" << endl; break;
		case 'C':cout << "Valg C" << endl; break;



		default: skrivMeny(); break;
		}	
		kommando = les();
	}

	//skrivTilFil();
	steder.skrivTilFilSteder();
	return 0;
	}


void skrivMeny() {
	
   cout << "K D: Displayer kunde data " << endl
		<< "K N: Legger til ny kunde" << endl
		<< "K E: Endrer data for en kunde" << endl
		<< "\nS D: Displayer data anng�ende sted " << endl
		<< "S N: Legger til nytt Sted " << endl
		<< "\nO D: Displayer Oppsett" << endl
		<< "O N: Nytt Oppsett " << endl
		<< "O E: Endre Oppsett " << endl
		<< "\nA D: Display arrangement " << endl
		<< "A N: Nytt Arrangement" << endl
		<< "A S: Slett arrangement" << endl
		<< "A K: Kj�p Billett" << endl;

}
