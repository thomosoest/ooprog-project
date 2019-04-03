#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "funksjoner.h"
#include "arrangementer.h"
#include "arrangement.h"
#include "sted.h"
#include "steder.h"
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
	
	int opsNr, f;												//Oppsettnr
	char stedNavn[STRLEN];										//Navn paa sted i steder
	char arrNvn[STRLEN];										//Navn paa arrangement
	Arrangement * arrangement;									//arrangementpeker
	List * liste;												//listepeker


	
	do {
		lesTekst("Navn paa sted: ", stedNavn, STRLEN);			//Sjekker om gyldig stedsnavn
		opsNr = lesTall("Oppsettnr: ", 1, 5);					//Leser inn oppsettnr
	} while (!steder.finnesStedOgOps(stedNavn,opsNr));

	

	opsNr = lesTall("Oppsettnr: ", 1, 5);						//Leser inn oppsettnr
																//!!HER MAA DET IMPLEMENTERES EN SJEKKMEKANISME!!

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
	cout << "Kjoper billett" << endl;
}

void Arrangementer::meny() { //Meny for aa navigere i arrangementer
	char kommando = 'E';

	kommando = les();
	switch (kommando) {
	case 'D': displayArrangement();	break;	//Displayer 
	case 'N': nyArrangement();		break;	//Lager nytt arrangement
	case 'E': //endreArrangement();		break;		//Frivillig
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
			arranvn = tempArrangement->hentnr();
			arrangementListe->add(tempArrangement);
			filnavn[4] = 48 + arranvn / 10;	//Setter nr 5 i arrayen. bare over 0 om over 10
			filnavn[5] = 48 + arranvn % 10;	//Setter nr 6 i arrayen. om over 10 legges til i skuff [4]
			const int result = remove(filnavn);
			tempArrangement = (Arrangement*)arrangementListe->destroy(navn);
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
	char buff[STRLEN];
	Arrangement * tempArrangement;

	lesTekst("Skriv inn teksten du vil soeke paa: ", buff, STRLEN);

	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		tempArrangement->tekstSjekk(buff);			//Displayer artisten vha funksjon i arrangement
		arrangementListe->add(tempArrangement); //Legger arrangement tilbake
	}
}

void Arrangementer::displaySted(){
	int n = 0;
	char buff[STRLEN];
	Arrangement * tempArrangement;

	lesTekst("Skriv inn stedets navn: ", buff, STRLEN);

	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		tempArrangement->stedSjekk(buff);			//Displayer artisten vha funksjon i arrangement
		arrangementListe->add(tempArrangement); //Legger arrangement tilbake
	}
}	



void Arrangementer::displayDato() {
	int n = 0;
	Arrangement * tempArrangement;

	cout << "\nHvilken dato vil du ha arrangement fra?  "; 
	n = lesTall("Gyldig dato er paa formatet: DDMMAA ", 000000, 999999);
	
	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		tempArrangement->datoSjekk(n);			//Skriver ut datoen
		arrangementListe->add(tempArrangement); //Legger arrangement tilbake
	}

}

void Arrangementer::displayType() {
	/*int n = 0;

	Arrangement * tempArrangement;

	cout << "\nHvilken type arrangement vil du ha arrangement for?  ";
	n = lesTall("Gyldig tall 1-7: ", 1, 7);

	switch (n)			// VIRKER IKKE, skal egentlig sette riktig type arrangement 
	{
	case 1: type = musikk;	break;
	case 2: type = sport;	break;
	case 3: type = teater;	break;
	case 4: type = show;	break;
	case 5: type = kino;	break;
	case 6: type = familie; break;
	case 7: type = festival; break;
	}

	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		tempArrangement->typeSjekk(n);			//Skriver ut datoen
		arrangementListe->add(tempArrangement); //Legger arrangement tilbake
	}
	*/
}

void Arrangementer::displayArtist() {

	int n = 0;
	char buff[STRLEN];


	Arrangement * tempArrangement;

	lesTekst("Skriv inn artistens navn: ", buff, STRLEN);

	for (int i = 1; i <= arrangementListe->noOfElements(); i++) {
		tempArrangement = (Arrangement*)arrangementListe->removeNo(i);
		tempArrangement->artistSjekk(buff);			//Displayer artisten vha funksjon i arrangement
		arrangementListe->add(tempArrangement); //Legger arrangement tilbake
	}


}

void Arrangementer::displayBillett() {

}



#endif
