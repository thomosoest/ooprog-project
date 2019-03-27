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
	cout << "\n\tHar: " << sisteOppsett << " oppsett";

}

void Sted::skrivTilFilSted(ofstream & utfil) { //Skriver fil til sted
	
	utfil << stednavn << "\n";
}

void Sted::nyVrimle(char * t, int i) { //Far inn 't' som navn paa vrimleobjekt og 'i' som hvilket oppsett det er

	oppsett[i]->add(new Vrimle(t));
}

void Sted::nyStoler(char *t, int i)  { //Far inn 't' som navn paa stolereobjekt og 'i' som hvilket oppsett det er
	oppsett[i]->add(new Stoler(t));
}

int Sted::hentNrOppsett() { 
	
	int i;
	for (i = 1; i <= 5; i++) {
		if (oppsett[i] == nullptr) {           //Om ikke liste
			sisteOppsett = i-1;
			return i-1;						   //returnerer 'i' i hvilken arraynuummer listen er
			
		}
	}
	return 0;									//Om det er lister i alle oppsett returner 0.

}

int Sted::lagNyttOppsettListe() {
	int i;
	for (i = 1; i <= 5; i++) {
		if (oppsett[i] == nullptr) {           //Om ikke liste
			oppsett[i] = new List(Sorted);	   //lager en liste
			sisteOppsett = i;
			return i;
		}
	}
	return 0;
}

void Sted::displayOppsett(int i) { //Faar inn 'i' og kaller paa displayfunksjon til gitt oppsett 'i'
	
	oppsett[i]->displayList();
}



List* Sted::kopier(int nr) { //kopiert fra frode
	
	List* liste = NULL;
	int i, ant;
	Sone *sone, *kopi;

	if (nr >= 1 && nr <= sisteOppsett) {
		ant = oppsett[nr]->noOfElements();

		liste = new List(Sorted);
		for (i = 1; i <= ant; i++) {
			sone = (Sone*)oppsett[nr]->removeNo(i);
			if (sone->hentType() == 'S') { kopi = new Stoler(*((Stoler*)sone)); cout << "\t\tKOPIERT STOLER"; }
			else { kopi = new Vrimle(*((Vrimle*)sone)); cout << "\t\tKOPIERT VRIMLE";
			}
			oppsett[nr]->add(sone);
			liste->add(kopi);
		}
	}
	return liste;
}
void Sted::nyttOppsett(List* liste) {
	if (sisteOppsett < OPS)
		oppsett[++sisteOppsett] = liste;
	else cout << "DENNE SKAL IKKE KOMME. SISTEOPPSETT ER OVER 5";
}
#endif