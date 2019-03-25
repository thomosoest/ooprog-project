#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <fstream>
#include "funksjoner.h"
#include "steder.h"
#include "sone.h"



using namespace std;


Sone::Sone()
{
	cout << "Skal ikke ha tomme constructorer i sone";
}

Sone::Sone(char * t) : TextElement(t) { //Faar med sonenavn som parameter og sender videre til textelement

	sonenavn = t;

	pris = lesTall("Billettpris", 1, 2500);        //Leser inn pris per billett
	antBill = lesTall("Antall totalt", 1, 4000);   //Leser inn totalt antall billetter til salgs


}



void Sone::nyttOppsett() {

}



void Sone::display() {
	
	cout << "\nSonenavn: " << sonenavn;
	cout << "\nAntall billetter: " << antBill;
	cout << "\nPris: " << pris;
}
#endif