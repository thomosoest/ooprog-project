#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "funksjoner.h"
#include "arrangementer.h"
#include "arrangement.h"
#include "sted.h"
#include "steder.h"
#include "kunder.h"
#include "const.h"
#include <fstream>
#include <cstdio>


extern Steder steder;


using namespace std;


Arrangementer::Arrangementer() {			//initierer arrangement 

	sisteArrangement = 0;					//Setter siste unike
	arrangementListe = new List(Sorted);	//Lager ny sortert arr liste

}

void Arrangementer::nyArrangement() {		//Kopiert fra frode

	int opsNr;													//Oppsettnr
	char stedNavn[STRLEN];										//Navn paa sted i steder
	char arrNvn[STRLEN];										//Navn paa arrangement
	Arrangement * arrangement;									//arrangementpeker
	List * liste;												//listepeker
	
	do {
		lesTekst("Navn paa sted: ", stedNavn, STRLEN);			//Sjekker om gyldig stedsnavn
		opsNr = lesTall("Oppsettnr: ", 1, 5);					//Leser inn oppsettnr
	} while (!steder.finnesStedOgOps(stedNavn,opsNr));			//Saa lenge baade sted og oppsett finnes

	lesTekst("Arrangementets navn: ", arrNvn, STRLEN);			//Leser inn arrangementnavn

	arrangement = new Arrangement(arrNvn, ++sisteArrangement);	//Kaller paa contructor i arrangement og sender med arrnavn
	liste = steder.kopier(stedNavn, opsNr);						//listepeker peker paa oppsett i sted
	arrangement->lesData(liste, stedNavn);						//lagrer oppsettet i ett arrangement samt navn paa sted
	arrangement->skrivTilFil();									//Skriver oppsett til fil
	arrangementListe->add(arrangement);							//Legger arrangementet i listen
}




void Arrangementer::displayArrangement() { //Displayer arrangement
	char kommando = 'E'; 

	cout << "Arrangementer kan vises paa ulike maater: \n\n"
		<< "1: Alle arrangementer\n"
		<< "2: Hele eller deler av en tekst\n"
		<< "3: Displayes via Sted\n"
		<< "4: Gitt dato\n"
		<< "5: Gitt type\n"
		<< "6: Gitt artist\n"
		<< "7: Alle data inkludert billettsalg paa ett arrangement\n";

	kommando = les();
	
	//Sender til de forskjellige display funksjonene
	switch (kommando) {
	case '1': arrangementListe->displayList(); break;
	case '2': displayTekst();	break;
	case '3': displaySted();	break;
	case '4': displayDato();	break;
	case '5': displayType();	break;
	case '6': displayArtist();	break;
	case '7': displayBillett(); break;
	default:	cout << "\n Feil input\n"; 	break;
	}

}


void Arrangementer::kjopBillett() {			//Kjoper billett
	int n = 0;
	Arrangement * temp = NULL;
	
	arrangementListe->displayList();
	n = lesTall("Skriv inn nr paa arrangement: ", 1, arrangementListe->noOfElements());

		temp = (Arrangement*)arrangementListe->removeNo(n);
		temp->billettKjop();									//Displayer vha funksjon i arrangement
		arrangementListe->add(temp);							//Legger arrangement tilbake
	
}

void Arrangementer::meny() { //Meny for aa navigere i arrangementer
	char kommando = 'E';

	kommando = les();
	switch (kommando) {
	case 'D': displayArrangement();	break;	//Displayer 
	case 'N': nyArrangement();		break;	//Lager nytt arrangement
	case 'E': endreArrangement();	break;		//Frivillig
	case 'S': slettArrangement();	break;	//maa lages
	case 'K': kjopBillett();		break;	//maa lages
	}


}


void Arrangementer::slettArrangement() {		//Sletter arrangement
	char navn[STRLEN];							//Hjelpe variabler
	char kommando = 'E';
	int arranvn;
	char filnavn[11] = "ARR_nr.DTA";		//initialiserer en char array
	
	cout << "(J) Hvis du vil slette ett arrangement\n(N) for aa avbryte";
	kommando = les();							//sjekker om man virkelig vil slette

	if (kommando == 'J')	{
		cout << "\n\tHvilket arrangement vil du slette?\n\n";
		arrangementListe->displayList();			//Displayer liste saa man ser arrangementnavn
		lesTekst("\n\nHvilkett arrangement vil du slette?`", navn, STRLEN); 

		if (arrangementListe->inList(navn)){		//Sjekker at arrangementet eksisterer
			Arrangement* tempArrangement;
			
			tempArrangement = (Arrangement*)arrangementListe->remove(navn);		//Fjerner kunden fra lista og legger den i tempKunde
			arranvn = tempArrangement->hentnr();								//for aa faa tak i arrangementnr
			arrangementListe->add(tempArrangement);
			filnavn[4] = 48 + arranvn / 10;			//Setter nr 5 i arrayen. bare over 0 om over 10
			filnavn[5] = 48 + arranvn % 10;			//Setter nr 6 i arrayen. om over 10 legges til i skuff [4]
			const int result = remove(filnavn);		//Fjerner filen fra hdd/ssd
			tempArrangement = (Arrangement*)arrangementListe->destroy(navn);	//sletter arrangementet
			cout << "\nKunden er slettet.\n";
		}
		else cout << "\nIngen arrangement funnet med det navnet.";
	}
	else cout << "\nArrangement ikke slettet\n";	
}


void Arrangementer::lesFil() {	//Leser fra fil
	ifstream innfil("ARRANGEMENTER.DTA");
	int nr;
	int antArrangement;

	char navn[STRLEN];

	if (innfil) {
		innfil >> antArrangement; innfil.ignore();
		nr = (arrangementListe->noOfElements()) + 1;
		for (int i = 1; i <= antArrangement; i++) {		//For hvert arrangement

			innfil.getline(navn, STRLEN);				//Sender med navn
			arrangementListe->add(new Arrangement(navn, innfil));
			nr++;
			sisteArrangement++;
		}
	}
	else cout << "\n\t\tFinner ikke fil med arrangementer: ARRANGEMENTER.DTA\n\n";	
}

void Arrangementer::skrivFil() {
	ofstream utfil("ARRANGEMENTER.DTA");
	Arrangement * temp;

	utfil << (arrangementListe->noOfElements()) << "\n";
	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {

		temp = (Arrangement*)arrangementListe->removeNo(i);
		temp->skrivFil(utfil);
		arrangementListe->add(temp);
	}
}

//Display funksjoner:

void Arrangementer::displayTekst() {
	int n = 0;
	bool funnet = 0;
	char buff[STRLEN];
	Arrangement * tempArrangement;

	lesTekst("Skriv inn teksten du vil soeke paa: ", buff, STRLEN);

	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		if (tempArrangement->tekstSjekk(buff)) funnet = 1;			//Displayer artisten vha funksjon i arrangement
		arrangementListe->add(tempArrangement); //Legger arrangement tilbake
	}
	if (funnet == 0) cout << "\nArrangement ikke funnet.";
}

void Arrangementer::displaySted(){
	int n = 0;
	bool funnet = 0;
	char buff[STRLEN];
	Arrangement * tempArrangement;

	lesTekst("Skriv inn stedets navn: ", buff, STRLEN);

	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		if (tempArrangement->stedSjekk(buff)) funnet = 1;			//Displayer artisten vha funksjon i arrangement
		arrangementListe->add(tempArrangement); //Legger arrangement tilbake
	}
	if (funnet == 0) cout << "\nArrangement ikke funnet.";
}	



void Arrangementer::displayDato() {
	int n = 0;
	bool funnet = 0;
	Arrangement * tempArrangement;

	cout << "\nHvilken dato vil du ha arrangement fra?  "; 
	n = lesTall("Gyldig dato er paa formatet: DDMMAA ", DATOMIN, DATOMAX);
	
	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		if (tempArrangement->datoSjekk(n)) funnet = 1;		//Skriver ut datoen
		arrangementListe->add(tempArrangement); //Legger arrangement tilbake
	}
	if (funnet == 0) cout << "\nArrangement ikke funnet.";
}

void Arrangementer::displayType() {
	int n = 0;
	bool funnet = 0;
	Arrangement * tempArrangement;

	cout << "\n\tHvilken type arrangement vil du ha arrangement for?  \n"
		<< "\t1: Musikk\n"
		<< "\t2: Sport\n"
		<< "\t3: Teater\n"
		<< "\t4: Show\n"
		<< "\t5: Kino\n"
		<< "\t6: Familie\n"
		<< "\t7: Festival\n";

	n = lesTall("Gyldig tall 1-7: ", 1, 7);

	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		if (tempArrangement->typeSjekk(n)) funnet = 1;			//Skriver ut datoen
		arrangementListe->add(tempArrangement); //Legger arrangement tilbake
	}
	if (funnet == 0) cout << "\nArrangement ikke funnet.";
}

void Arrangementer::displayArtist() {
	int n = 0;
	char buff[STRLEN];
	bool funnet = 0;
	Arrangement * tempArrangement;

	lesTekst("Skriv inn artistens navn: ", buff, STRLEN);

	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		if (tempArrangement->artistSjekk(buff)) funnet = 1;		//Displayer artisten vha funksjon i arrangement
		arrangementListe->add(tempArrangement);					//Legger arrangement tilbake
	}
	if (funnet == 0) cout << "\nArrangement ikke funnet.";
}

void Arrangementer::displayBillett() {
	int n = 0;
	bool funnet = 0;
	Arrangement * tempArrangement;

	n = lesTall("Gyldig tall 1-7: ", 1, 99);

	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);	
		if (tempArrangement->billettUtskrift(n)) funnet = 1;			//Displayer vha funksjon i arrangement
		arrangementListe->add(tempArrangement);							//Legger arrangement tilbake
	}
	if (funnet == 0) cout << "\nArrangement ikke funnet.";
}

void Arrangementer::endreArrangement() {

	int i, n;
	n = arrangementListe->noOfElements();
	if (n >= 1) {
		i = lesTall("Hvilket arrangement vil du endre på? ", 1, n);
		Arrangement* temp;
		temp = (Arrangement*)arrangementListe->removeNo(i);		//Fjerner kunden fra lista og legger den i tempKunde
		temp->endreArrangement();								//Sender til funksjon som forandrer dataene
		arrangementListe->add(temp);							//Leger den endrede kunden tilbake
	}
	else cout << "\nIngen kunder i listen\n";

}

#endif
