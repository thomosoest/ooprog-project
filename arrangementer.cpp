#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "funksjoner.h"
#include "arrangementer.h"
#include "arrangement.h"
#include "const.h"
#include <fstream>


using namespace std;


Arrangementer::Arrangementer() {			//initierer arrangement 

	sisteArrangement = 1;					//Setter siste unike
	arrangementListe = new List(Sorted);	//Lager ny sortert arr liste

}



void Arrangementer::nyArrangement() {		
	
	int n = 0;
	int o = 0;
	char stedNavn[STRLEN];
	char arrangementsNavn[STRLEN];

	lesTekst("Spillestedets navn: ", stedNavn, STRLEN); // Spoerres om spillestedsnavn
	//sted.sjekkSted(bool);								Sjekker om stedet finnes 
	lesTekst("Arrangementets navn: ", arrangementsNavn, STRLEN); //Spoerres om arr navn

	n = lesTall("Oppsettnummer:  ", 0000, 9999);		// Spoerres om oppsettnummer
	//kopierOppsett();						Funksjon for aa kopiere
	
	arrangementListe->add(new Arrangement(arrangementsNavn, stedNavn, sisteArrangement));
	// Sendes til arrangement for aa lese inn all data
	++sisteArrangement; // Oker siste
	
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
	//case 'E': endreKunde();		break;	//Frivillig
	case 'S': slettArrangement();	break;	//maa lages
	case 'K': kjopBillett();		break;	//maa lages
	}


}


void Arrangementer::slettArrangement() {		//Sletter arrangement
	char navn[STRLEN];			//Hjelpe variabler
	char kommando = 'E';

	cout << "\n Tast inn 'J' Hvis du vil slette ett arrangement ";
	kommando = les();							//sjekker om man virkelig vil slette

	if (kommando == 'J')	{
		cout << "\n\tHvilket arrangement vil du slette?\n\n";

		arrangementListe->displayList();			//Displayer liste saa man ser arrangementnavn

		lesTekst("\n\nHvilkett arrangement vil du slette?`", navn, STRLEN); 

		if (arrangementListe->inList(navn)){		//Sjekker at arrangementet eksisterer
			Arrangement* tempArrangement;
			// Funksjon for aa slette riktig fil, skal kalles her
			tempArrangement = (Arrangement*)arrangementListe->destroy(navn);		//Fjerner kunden fra lista og legger den i tempKunde
		cout << "\nkunden er slettet.\n";
		}
		else	{
			cout << "\nIngen arrangement funnet med det navnet.";
		}
	}
	else
	{
		cout << "\nArrangement ikke funnet.\n";
	}
}


void Arrangementer::lesFil() {	// Leser fra fil 
	ifstream innfil("ARRANGEMENTER.DTA");
	int nr;
	int antArrangement;

	char navn[STRLEN];

	if (innfil) {
		innfil >> antArrangement; innfil.ignore();
		nr = (arrangementListe->noOfElements()) + 1;
		for (int i = 1; i <= antArrangement; i++) {

			innfil.getline(navn, STRLEN); 
			arrangementListe->add(new Arrangement(navn, innfil));
			nr++;
		}
	}
	else cout << "\n\t\tFinner ikke fil med arrangementer: ARRANGEMENTER.DTA\n\n";	
}

void Arrangementer::skrivFil() {
	ofstream utfil("ARRANGEMENTER1.DTA");
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