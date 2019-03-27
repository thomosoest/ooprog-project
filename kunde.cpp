#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include "kunde.h"
#include "ListTool2B.h"
#include "funksjoner.h"
#include "const.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Kunde::Kunde(int n) : NumElement(n)  //	"n" sendes til NumElement
{

	char buff[STRLEN];

	lesTekst("Kundens navn: ", buff, STRLEN);
	navn = new char[strlen(buff) + 1]; strcpy(navn, buff);
	
	lesTekst("Kundens adresse: ", buff, STRLEN);
	gateadr = new char[strlen(buff) + 1]; strcpy(gateadr, buff);

	lesTekst("Kundens poststed: ", buff, STRLEN);
	poststed = new char[strlen(buff) + 1]; strcpy(poststed, buff);

	lesTekst("Kundens mail: ", buff, STRLEN);
	mail = new char[strlen(buff) + 1]; strcpy(mail, buff);

	tlf = lesTall("Telefon: ", 10000000, 999999999);
	postnr = lesTall("Postnummer: ", 0000, 9999);


	cout << "Du har nå lagt til en ny kunde." << endl;


};


Kunde::Kunde(int n, ifstream & innfil) : NumElement(n)
{
	char buff[STRLEN];
	id = n;
	innfil.getline(buff, STRLEN);
	navn = new char[strlen(buff) + 1]; strcpy(navn, buff);

	innfil.getline(buff, STRLEN);
	gateadr = new char[strlen(buff) + 1]; strcpy(gateadr, buff);

	innfil.getline(buff, STRLEN);
	poststed = new char[strlen(buff) + 1]; strcpy(poststed, buff);

	innfil.getline(buff, STRLEN);
	mail = new char[strlen(buff) + 1]; strcpy(mail, buff);

	innfil >> tlf;    innfil.ignore();
	innfil >> postnr;    innfil.ignore();


}

void Kunde::endreKunde() {
	
	char kommando = 'E';
	char buff[STRLEN];

	cout << "\n Hva vil du endre på i kunden? : \n"
		<< "\t1: Navn\n"
		<< "\t2: Adresse\n"
		<< "\t3: poststed\n"
		<< "\t4: Mail\n"
		<< "\t5: Telefonnummer\n"
		<< "\t6: Post nummer\n"
		<< "\n\nLoopen forsetter til du trykker Q\n";


	do {
		cout << "\nSkriv inn kommando: ";
		kommando = les();							// Les funksjonen får og uppcaser kommandoen


		switch (kommando) {

		case '1': {	lesTekst("Kundens navn: ", buff, STRLEN);
			navn = new char[strlen(buff) + 1]; strcpy(navn, buff); 
		}	  break;

		case '2': {	lesTekst("Kundens adresse: ", buff, STRLEN);
			gateadr = new char[strlen(buff) + 1]; strcpy(gateadr, buff); 
		} break;

		case '3': {
			lesTekst("Kundens poststed: ", buff, STRLEN);
			poststed = new char[strlen(buff) + 1]; strcpy(poststed, buff); 
		} break;

		case '4': {	lesTekst("Kundens mail: ", buff, STRLEN);
			mail = new char[strlen(buff) + 1]; strcpy(mail, buff); 
		} break;

		case '5': {	tlf = lesTall("Telefon: ", 10000000, 999999999); 
		} break;

		case '6': {	postnr = lesTall("Telefon: ", 10000000, 999999999); 
		} break;

		default:  break;
		}
	} while (kommando != 'Q');


}


void Kunde::display()
{
	cout << "\n\t Kunde ID: \t\t"		<< id << '\n'
		<< "\t Navn: \t\t\t"			<< navn << '\n'
		<< "\t Adresse: \t\t"		<< gateadr << '\n'
		<< "\t Poststed: \t\t"		<< poststed << '\n'
		<< "\t Mail:  \t\t"			<< mail << '\n'
		<< "\t Telefonnummer: \t"	<< tlf << '\n'
		<< "\t Postnummer: \t\t"	<< postnr << '\n';
}


bool Kunde::riktigNavn(char* nvn)	{
	return !strcmp(navn, nvn);
}

void Kunde::skrivFil(ofstream & utfil)
{
	cout << "\n\n Skriver til fil\n\n";
	utfil << navn << "\n";
	utfil << gateadr << "\n";
	utfil << poststed<< "\n";
	utfil << mail << "\n";
	utfil << tlf << "\n";
	utfil << postnr << "\n";

}


#endif