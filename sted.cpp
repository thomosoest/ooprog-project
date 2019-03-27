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

	cout << "\nNavn paa spillested: " << stednavn; 
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
	
	return sisteOppsett;
}
void Sted::sisteOppsettPlussEn() {
	sisteOppsett++;
}
int Sted::lagNyttOppsettListe() {
	
	for (int i = 1; i <= OPS; i++) {
		if (oppsett[i] == nullptr) {           //Om ikke liste
			oppsett[i] = new List(Sorted);	   //lager en liste
			return i;						   //returnerer 'i' i hvilken arraynuummer listen er
		}
	}
	return 0;
}

void Sted::displayOppsett(int i) { //Faar inn 'i' og kaller paa displayfunksjon til gitt oppsett 'i'
	
	oppsett[i]->displayList();
}

void Sted::nyttOppsett(List* liste) {				//faar inn liste som parameter 
	if (sisteOppsett <= OPS)						//Dobbel sjekk om sisteOppsett er lovlig
		oppsett[++sisteOppsett] = liste;			//Legger listen fra parameter inn i arrayen.
	else cout << "DENNE SKAL IKKE KOMME. SISTEOPPSETT ER OVER 5";
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

#endif