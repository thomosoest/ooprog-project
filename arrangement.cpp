
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
//Inkluderte filer
#include "arrangementer.h"
#include "arrangement.h"
#include "ListTool2B.h"
#include "funksjoner.h"
#include "const.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;




Arrangement::Arrangement(char t[], char a[], int n) : TextElement(t) // Navnet t sendes til TextElement
{
	char buff[STRLEN];
	int nr = 0;

	arrangementnavn = new char[strlen(t) + 1]; strcpy(arrangementnavn, t);
	spillested = new char[strlen(a) + 1]; strcpy(spillested, a);
	arrangementNr = n;

	lesTekst("Artistens navn: ", buff, STRLEN);
	artist = new char[strlen(buff) + 1]; strcpy(artist, buff);

	dato = lesTall("Datoen for arrangementet(DDMMAA): ", 000001, 999999);
	minutt = lesTall("Tid minutt(00-59): ", 00, 59);
	time = lesTall("Tid time(00-24): ", 00, 24);

	cout << "hvilken type arrangement er dette?\n"
		<< "1: Musikk 2: Sport 3: Teater 4: Show 5: Kino 6: Familie 7: Festival :";

	cin >> nr; cin.ignore();
	switch (nr)			// VIRKER IKKE, skal egentlig sette riktig type arrangement 
	{
	case 1: type = musikk;	break;
	case 2: type = sport;	break;
	case 3: type = teater;	break;
	case 4: type = show;	break;
	case 5: type = kino;	break;
	case 6: type = familie; break;
	case 7: type = festival; break;
	}

};

Arrangement::Arrangement(char t[STRLEN], ifstream & innfil) : TextElement(t)
{		// Leser inn Arrangements data fra fil
	char buff[STRLEN];

	arrangementnavn = new char[strlen(buff) + 1]; strcpy(arrangementnavn, t); // Kopierer medsendt char til arr.navn

	innfil.getline(buff, STRLEN);
	spillested = new char[strlen(buff) + 1]; strcpy(spillested, buff);

	innfil.getline(buff, STRLEN);
	artist = new char[strlen(buff) + 1]; strcpy(artist, buff);

	innfil >> arrangementNr;    innfil.ignore();
	innfil >> dato;    innfil.ignore();
	innfil >> minutt;    innfil.ignore();
	innfil >> time;    innfil.ignore();
}



void Arrangement::display() {
	cout << "\n\t Arrangements ID: \t\t" << arrangementNr << '\n'
		<< "\t Arrangementets navn: \t\t" << arrangementnavn << '\n'
		<< "\t Spillested: \t\t\t" << spillested << '\n'
		<< "\t Artistens navn: \t\t" << artist << '\n'
		<< "\t Dato:  \t\t\t" << dato << '\n'
		<< "\t Klokkeslett: \t\t\t" << time << ":" << minutt << '\n' 
		<< "\t Arrangementets type: \t\t" << type << '\n';
	

}

void Arrangement::skrivFil(ofstream & utfil) {
	{
		cout << "\n\n Skriver til fil\n\n";
		utfil << arrangementnavn << "\n";
		utfil << spillested << "\n";
		utfil << artist << "\n";
		utfil << arrangementNr << "\n";
		utfil << dato << "\n";
		utfil << minutt << "\n";
		utfil << time << "\n";

	}

}


bool Arrangement::riktigSted(char* nvn) {
	return !strcmp(spillested, nvn);
}

bool Arrangement::datoSjekk(int n) {
	
	
	
	
	if (dato = n)
	{
		cout << '\n' << arrangementnavn << '\n';
		//return true;
	}
	else
	{
		cout << '\n' << "Arrangement ikke funnet" << '\n';
	}

	return (1);
} 





#endif