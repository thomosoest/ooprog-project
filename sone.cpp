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

	pris = lesTall("Billettpris", 1, 2500);        //Leser inn pris per billett
	antBill = lesTall("Antall totalt", 1, 4000);   //Leser inn totalt antall billetter til salgs
}

void Sone::display() {
	
	cout << "\nSonenavn: " << text; 
	cout << "\nAntall billetter: " << antBill;
	cout << "\nPris: " << pris;
}

char Sone::hentType() { //Virituell funksjon som returnerer type objekt Stoler/Vrimle
	return type;
}

Sone::Sone(Sone* s) : TextElement(s->text) { //Kopiert fra frode
	antBill = s->antBill;
	pris = s->pris;
	//antSolgt = s->antSolgt;
}

void Sone::skrivTilfil(ofstream & utfil) { //Virituell funksjon som kaller paa skriv til fil til Vrimle/Stoler

}

Sone::Sone(char t[], ifstream & innfil) : TextElement(t) { //Faar inn navn fra Stoler/Vrimle og sender opp til TextElement

}

#endif