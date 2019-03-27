
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

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
	
	arrangementnavn = new char[strlen(t) + 1]; strcpy(arrangementnavn, t);
	spillested = new char[strlen(a) + 1]; strcpy(spillested, a);
	arrangementNr = n;

	lesTekst("Artistens navn: ", buff, STRLEN);
	artist = new char[strlen(buff) + 1]; strcpy(artist, buff);

	dato = lesTall("Datoen for arrangementet(DDMMAA): ", 000001, 999999);
	minutt = lesTall("Tid minutt(00-59): ", 00, 59);
	time = lesTall("Tid time(00-24): ", 00, 24);
};



void Arrangement::display() {
	cout << "\t Arrangements ID: \t\t" << arrangementNr << '\n'
		<< "\t Arrangementets navn: \t\t" << arrangementnavn << '\n'
		<< "\t Spillested: \t\t" << spillested << '\n'
		<< "\t Artistens navn: \t\t" << artist << '\n'
		<< "\t Dato:  \t\t" << dato << '\n'
		<< "\t Klokkeslett: \t" << time << ":" << minutt << '\n';

}

void Arrangement::skrivFil() {

}



#endif