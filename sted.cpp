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
	
};


void Sted::display() {

	cout << "\nNavn paa spillested: " << text; //Stedsnavn
	cout << "\n\tHar: " << sisteOppsett << " oppsett";

}

void Sted::skrivTilFilSted(ofstream & utfil) { //Skriv til fil funksjon for sted
	Sone * temp;												   //Lager en temp sonepeker
	utfil << text << "\n";										   //Skriver ut navn paa sted
	utfil << sisteOppsett << "\n";								   //Skriver ut antall oppsett
	for (int i = 1; i <= sisteOppsett; i++) {					   
		utfil << oppsett[i]->noOfElements() << "\n";			   //Skriver ut hvor mange objekter i oppsettarrayen
		for (int j = 1; j <= oppsett[i]->noOfElements(); j++) {	   
			temp =(Sone*) oppsett[i]->removeNo(j);				   //Tar ett element ut av arrayen
			temp->skrivTilfil(utfil);							   //Kaller paa virituell skriv til fil funksjon for sone
			oppsett[i]->add(temp);								   //Legger objektet tilbake i arrayen
		}														   
	}
}

void Sted::nyVrimle(char * t, int i) { //Far inn 't' som navn paa vrimleobjekt og 'i' som hvilket oppsett det er

	oppsett[i]->add(new Vrimle(t));
}

void Sted::nyStoler(char *t, int i)  { //Far inn 't' som navn paa stolereobjekt og 'i' som hvilket oppsett det er
	
	oppsett[i]->add(new Stoler(t));
}

int Sted::hentNrOppsett() { //Returnerer sist bruke oppsettnr
	
	return sisteOppsett;
}
void Sted::sisteOppsettPlussEn() { //For aa plluse paa sisteOppset utenfor Sted
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

void Sted::kopiOppsett(List* liste) {				//faar inn liste som parameter 
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
			if (sone->hentType() == 'S')  kopi = new Stoler(*((Stoler*)sone));
			else kopi = new Vrimle(*((Vrimle*)sone));
			oppsett[nr]->add(sone);
			liste->add(kopi);
		}
	}
	return liste;
}

Sted::Sted(char  navn[], ifstream & innfil) : TextElement(navn) { //Sender navn opp til TekstElement
	int antOps;													//Antall oppsett
	int antSoner;												//Antall soner
	char soneEllerVrimle;										//Char som avgjor om det er Stoler/Vrimle
	char soneNavn[STRLEN];										//Navn paa sone(Vrimle/Stoler)
	innfil >> antOps;											//Leser inn antall oppsett
	for (int i = 1; i <= antOps; i++) {							
		oppsett[i] = new List(Sorted);							//Lager en ny liste
		innfil >> antSoner;										//Leser inn antall soner
		for (int j = 1; j <= antSoner; j++) {					
			innfil >> soneEllerVrimle;							//Leser inn om det er Vrimle eller Stoler
			innfil >> soneNavn; //innfil.ignore();				//Leser inn navn paa sone(Vrimle/Stoler)
			if (soneEllerVrimle == 'S') 						//Om Stoler
				oppsett[i]->add(new Stoler(soneNavn, innfil));	//Kaller paa Stoler constructor og sender med navn og innfil
			else if (soneEllerVrimle == 'V') 					//Om Vrimle
				oppsett[i]->add(new Vrimle(soneNavn, innfil));	//Kaller paa Vrimle constructor og sender med navn og innfil
			sisteOppsett++;										//Plusser paa siste brukte oppsett int'en
		}
	}
}

void Sted::endreOppsett(int i) {
	Sone * sonePeker;
	int soneNr;
	char svar;
	char soneNavn[STRLEN];
	char * navn;


	soneNr = lesTall("Hvilken sone vil du endre paa: ", 1, oppsett[i]->noOfElements());
	cout << "Vil du:\n(S)lette ett objekt\n(E)ndre paa ett objekt\n(L)egge til ett objekt\n";
	svar = les();

	if (svar == 'E' || svar == 'S') {
		sonePeker = (Sone*)oppsett[i]->removeNo(soneNr);    //Tar objektet inn og ut fra listen for aa
		oppsett[i]->add(sonePeker);							//faa tak i navnet paa sonen
		navn = sonePeker->hentNavn();						//Henter navnet paa sonen
		oppsett[i]->destroy(navn);							//Sletter sonen
	}

	if (svar == 'E' || svar == 'L') {						
		lesTekst("Nytt sonenavn:", soneNavn, STRLEN);		//Leser inn sonenavn
		cout << "Ny Vrimle eller Stoler? "; svar = les();	//Leser inn Vrimle eller Stoler
		if (svar = 'V') nyVrimle(soneNavn, i);				//Legger til en ny vrimle i oppsettet
		else if (svar = 'S')nyStoler(soneNavn, i);			//Legger til en ny stoler i oppsettet
	}
}

#endif