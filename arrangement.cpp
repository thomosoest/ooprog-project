
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
//Inkluderte filer
#include "arrangementer.h"
#include "arrangement.h"
#include "ListTool2B.h"
#include "funksjoner.h"
#include "const.h"
#include "sone.h"
#include "sted.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
extern Sted sted;



Arrangement::Arrangement(char t[], int n) : TextElement(t) // Navnet t sendes til TextElement
{						//Hjelpevariabler
	char buff[STRLEN];
	int nr = 0;
						//Tar inn alle data for ett arrangement objekt
	
	arrangementNr = n;							

	lesTekst("Artistens navn: ", buff, STRLEN);
	artist = new char[strlen(buff) + 1]; strcpy(artist, buff);

	dato = lesTall("Datoen for arrangementet(DDMMAA): ", 10001, 999999);
	minutt = lesTall("Tid minutt: ", 00, 59);
	time = lesTall("Tid time: ", 00, 24);

	cout << "hvilken type arrangement er dette?\n"
		<< "1: Musikk 2: Sport 3: Teater 4: Show 5: Kino 6: Familie 7: Festival :";

	nr = lesTall("Gyldig tall 1-7: ", 1, 7);
	switch (nr)			// Setter riktig type arrangement 
	{
	case 1: type = musikk;	 break;
	case 2: type = sport;	 break;
	case 3: type = teater;	 break;
	case 4: type = show;	 break;
	case 5: type = kino;	 break;
	case 6: type = familie;  break;
	case 7: type = festival; break;
	}

}

Arrangement::Arrangement(char t[STRLEN], ifstream & innfil) : TextElement(t)
{		// Leser inn Arrangements data fra fil
	char buff[STRLEN];
	int n = 0;

	
	innfil.getline(buff, STRLEN);
	spillested = new char[strlen(buff) + 1]; strcpy(spillested, buff);

	innfil.getline(buff, STRLEN);
	artist = new char[strlen(buff) + 1]; strcpy(artist, buff);

	innfil >> n;					innfil.ignore();	//Tar in enumen som int
	innfil >> arrangementNr;		innfil.ignore();
	innfil >> dato;					innfil.ignore();
	innfil >> minutt;				innfil.ignore();
	innfil >> time;					innfil.ignore();
	type = static_cast<Typearrangement>(n);				//Caster inten n til over til enum type		
}


void Arrangement::skrivFil(ofstream & utfil) {
	{
		utfil << text << "\n";
		utfil << spillested << "\n";
		utfil << artist << "\n";
		utfil << type << "\n";
		utfil << arrangementNr << "\n";
		utfil << dato << "\n";
		utfil << minutt << "\n";
		utfil << time << "\n";
	}

};

//Display funksjoner:

// 1: Displayer alle data for alle arrangement
void Arrangement::display() {
	cout << "\n\t Arrangements ID: \t\t" << arrangementNr << '\n'
		<< "\t Arrangementets navn: \t\t" << text << '\n'
		<< "\t Spillested: \t\t\t" << spillested << '\n'
		<< "\t Artistens navn: \t\t" << artist << '\n'
		<< "\t Dato:  \t\t\t" << dato << '\n'
		<< "\t Klokkeslett: \t\t\t" << time << ":" << minutt << '\n';
	displayType();
		
}

//Display 2 - 7

// 2: Soker tekstene og skriver ut om den matcher med 3 eller mer karakterer
bool Arrangement::tekstSjekk(char* navn) {	
	int n = 0;
	
	if (!(strspn(navn, text) <= 3)) {	//3 eller mer karakterer via "strspn"
		display();						//Displayer om 3 eller mer matcher
		n++;							//Øker telleren
	}
	
	if (!(strspn(navn, spillested) <= 3)) {
		display();
		n++;
	}
	if (!(strspn(navn, artist) <= 3)) {
		display();
		n++;
	}

	if (n > 0) return true;				//Returner true om det har vært noen hit via søk
	else return false;

}

// 3: Skriver ut om sted matcher med teksten gitt
bool Arrangement::stedSjekk(char* navn) {
	if (!strcmp(navn, spillested)) {
		display();
		return true;
	}
		else return false;
}

// 4: Skriver ut om datoen matcher med den gitte
bool Arrangement::datoSjekk(int n) {
	if (dato == n) {
		display();
		lesOppsettFraFil();				//  NB! SKAL BARE VÆRE HER FOR TESTING
		return true;
	}
	else return false;
} 

// 5: Skriver ut om typen matcher med den gitte
bool Arrangement::typeSjekk(int n) {
	--n;
	type = static_cast<Typearrangement>(n);	//Caster inten n til over til enum type	
	if (type == n) {
		display();
		return true;
	}
	else return false;

}

// 6: Skriver ut data om artisten matcher med den gitte
bool Arrangement::artistSjekk(char* navn) {
	if (!strcmp(navn, artist)) {
		display();
		return true;
	}
	else return false;
}

// 7: Skal skrive ut alle data + billettsalget i alle soner om ett arrangementNummer
bool Arrangement::billettUtskrift(int n) {
	if (arrangementNr == n)
	{
		display();
		//Funksjon(?) som leser inn billettdata
		//Funksjon(?) som skriver utt billettdata
		//funksjon(?) som legger billettdata tilbake?
		return true;		//returner true om arrangementet ble funnet
	}
	else return false;		//returner false om arrangementet ikke ble funnet
}


void Arrangement::displayType(){
	switch (type)			// Konverterer enum type til tekst for utskrift
{
case 0: cout << "\t Arrangements type: musikk\n";	break;
case 1: cout << "\t Arrangements type: sport\n";	break;
case 2: cout << "\t Arrangements type: teater\n";	break;
case 3: cout << "\t Arrangements type: show\n";		break;
case 4: cout << "\t Arrangements type: kino\n";		break;
case 5: cout << "\t Arrangements type: familie\n";	break;
case 6: cout << "\t Arrangements type: festival\n";	break;
}
}

void Arrangement::lesData(List * l, char t[]) { 
	spillested = new char[strlen(t) + 1]; strcpy(spillested, t); 		//Spillested er lik navn i parameter
	oppsett = l;														//Oppsettlisten er lik listen i parameter
}

void Arrangement::skrivTilFil() {
	char filnavn[11] = "ARR_nr.DTA";		//initialiserer en char array
	filnavn[4] = 48 + arrangementNr / 10;	//Setter nr 5 i arrayen. bare over 0 om over 10
	filnavn[5] = 48 + arrangementNr % 10;	//Setter nr 6 i arrayen. om over 10 legges til i skuff [4]
	ofstream utfil(filnavn);
	
	Sone * temp;										   //Lager en temp sonepeker
	utfil << oppsett->noOfElements() << "\n";			   //Skriver ut hvor mange objekter i oppsettarrayen
	for (int i = 1; i <= oppsett->noOfElements(); i++) {	   
		temp =(Sone*) oppsett->removeNo(i);				   //Tar ett element ut av arrayen
		temp->skrivTilfil(utfil);						   //Kaller paa virituell skriv til fil funksjon for sone
		
		oppsett->add(temp);								   //Legger objektet tilbake i arrayen
	
	}														   
}


void Arrangement::lesOppsettFraFil() {
	int antSoner;
	char soneEllerVrimle;

	char filnavn[11] = "ARR_nr.DTA";		//initialiserer en char array
	filnavn[4] = 48 + arrangementNr / 10;	//Setter nr 5 i arrayen. bare over 0 om over 10
	filnavn[5] = 48 + arrangementNr % 10;	//Setter nr 6 i arrayen. om over 10 legges til i skuff [4]
	ifstream innfil(filnavn);				//Setter filnavnet lik det i "skrivTilFil"
	Sted * temp = NULL;
	List * liste = NULL;

	if (innfil) {

		oppsett = (temp->oppKopi(spillested, innfil));
		oppsett->displayList();				//Displayer for å vise at det fungerer
		
	}
	else cout << "\n\t\tFinner ikke fil med oppsettet\n\n";
}


int Arrangement::hentnr() {								   //Returnerer arrangementnummer for bruk utenfor arrangement
	return arrangementNr;
}

#endif