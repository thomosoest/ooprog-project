#include <iostream>
#include "funksjoner.h"
#include "kunder.h"
#include "kunde.h"
#include "const.h"
#include <fstream>


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

	char kommando = 'E'; int n = 0; 

	cout << "A: Alle data om alle kunder\n"
		 << "I: Alle data om en kunde via ID\n" 
		 << "N: Alle data om alle kunder med gitt navn\n";

	kommando = les();

	switch (kommando) {
	case 'A': kundeListe->displayList();  break;
	case 'I':  cout << "Hvilken kunde?(ID-nummer):  ";
		cin >> n;
		
		kundeListe->inList(n);


		if (kundeListe->inList(n))	{
			cout << "\nKunde funnet!\n";
			kundeListe->displayElement(n); break;	
		}
		else{
			cout << "\nkunde ikke funnet\n";
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

		if (!enFunnet) cout << ("\nKunde ikke funnet!\n");
	}	break; 

	default: cout << "\n Feil input\n"; break;
	}



	
}

void Kunder::endreKunde() {
	int i;
	cout << "Hvilken kunde vil du endre på?";
	cin >> i;
	Kunde* tempKunde;
	tempKunde = (Kunde*)kundeListe->remove(i);
}



void Kunder::meny()	{
	char kommando = 'E'; 

	kommando = les();
	switch (kommando) {
	case 'D': displayKunde(); break;
	case 'N': nyKunde(); break;
	case 'E': endreKunde(); break;
	case 'S': cout << "Denne funksjonen skal slette en kunde" << endl; break;
	}

}

void Kunder::lesFil() {
		ifstream innfil("KUNDER.DTA");
		int nr;
		int antkunder;

		if (innfil) {
			innfil >> antkunder; innfil.ignore();
			nr = (kundeListe->noOfElements()) + 1;
			for (int i = 1; i <= antkunder; i++) {
			
				
				cout << "\nAntall kunder på fil: " << nr << '\n';
				kundeListe->add(new Kunde(nr, innfil));
				nr++;
			}
		}

		else cout << "\n\t\tFinner ikke fil med kunder: KUNDER.DTA\n\n";

}
