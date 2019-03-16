#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include "kunde.h"
#include "ListTool2B.h"
#include <cstring>
#include "funksjoner.h"
#include "const.h"
#include <iostream>

using namespace std;

Kunde::Kunde(int n) : NumElement(n)  //	"n" sendes til NumElement
{

	char buf[STRLEN];

	lesTekst("Kundens navn: ", buf, STRLEN);
	navn = new char[strlen(buf) + 1]; strcpy(navn, buf);
	
	lesTekst("Kundens adresse: ", buf, STRLEN);
	gateadr = new char[strlen(buf) + 1]; strcpy(gateadr, buf);

	lesTekst("Kundens poststed: ", buf, STRLEN);
	poststed = new char[strlen(buf) + 1]; strcpy(poststed, buf);

	lesTekst("Kundens mail: ", buf, STRLEN);
	mail = new char[strlen(buf) + 1]; strcpy(mail, buf);

	tlf = lesTall("Telefon: ", 10000000, 999999999);
	postnr = lesTall("Postnummer: ", 0000, 9999);

	id = n;

	cout << "Du har nå lagt til en ny kunde." << endl;


};



void Kunde::display()
{
	cout << "\t Kunde ID: \t\t" << id << '\n'
		<< "\t Navn: \t\t" << navn << '\n'
		<< "\t Adresse: \t\t" << gateadr << '\n'
		<< "\t Poststed: \t\t" << poststed << '\n'
		<< "\t Mail:  \t\t" << mail << '\n'
		<< "\t Telefonnummer: \t" << tlf << '\n'
		<< "\t Postnummer: \t\t" << postnr << '\n';
};


bool Kunde::riktigNavn(char* nvn)
{
	return !strcmp(navn, nvn);
}



#endif