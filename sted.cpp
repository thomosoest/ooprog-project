#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include "sted.h"
#include "steder.h"
#include "ListTool2B.h"
#include "stoler.h"
#include "sone.h"
#include "vrimle.h"
#include <cstring>
#include "const.h"
#include <iostream>
#include <fstream>

using namespace std;





Sted::Sted(char t[]) : TextElement(t)  //	faar navn "t"  som sendes til TextElement
{
	stednavn = new char[strlen(t) + 1]; strcpy(stednavn, t); //lagrer stedsnavn i sted
};


void Sted::display() {

	cout << "\nNavn paa spillested: " << stednavn; //Skrver ut stedsnavn
}

void Sted::skrivTilFilSted(ofstream & utfil) { //Skriver fil til sted
	
	utfil << stednavn << "\n";
}

void Sted::nyVrimle(char * t, int i) { //Far inn 't' som navn paa vrimleobjekt og 'i' som hvilket oppsett det er


	oppsett[i]->add(new Vrimle(t));
	cout << "nyVrimle funksjon for debug\n"; //for debug
	

}

void Sted::nyStoler(char *t, int i)  {
	oppsett[i]->add(new Stoler(t));
	cout << "NyStoler funksjon for debug\n"; //for debug
}

int Sted::hentOppsett() { //Sjekker om det er laget liste til oppsett, hvis ikke lager en ny liste
	
	int i;
	for (i = 1; i <= 5; i++) {
		if (oppsett[i] == nullptr) {           //Om ikke liste
			oppsett[i] = new List(Sorted);	   //lager en liste
			return i;						   //og returnerer 'i' i hvilken arraynuummer listen er
			
		}
	}
	return 0;									//Om det er lister i alle oppsett returner 0.
}

void Sted::displayOppsett(int i) { //Faar inn 'i' og kaller paa displayfunksjon til gitt oppsett 'i'



	oppsett[i]->displayList();


}
#endif