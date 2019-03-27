
#ifndef __STED_H
#define __STED_H

#include "ListTool2B.h"
#include "const.h"
#include <iostream>
#include <fstream>

using namespace std;

class Sted : public TextElement {

private:
												
	char * stednavn;							//Navn paa sted
	List * oppsett[OPS];						//Liste array med ulike oppsett
	int sisteOppsett; 							//siste oppsett brukt
												
												
public:											
												
	Sted(char t[]);								//Constructor
	void display();								//Displayfunksjon
	void skrivTilFilSted(ofstream & utfil);		//Skriver fil til sted
	void nyVrimle(char *t, int i);				//Lager ett nytt vrimleobjekt
	void nyStoler(char *t, int i);				//Lager ett nytt stolerobjekt
	int hentNrOppsett();						//Returnerer sist brukte oppsett nr
	void displayOppsett(int i);					//Displayfunksjon for oppsett
	void nyttOppsett(List* liste);				//Lager nytt oppsett for kopieringsfunksjon
	List *kopier(int nr);						//Kopifunkjon for oppsett
	int lagNyttOppsettListe();					//Lager ny listeoppsett
	

};
#endif



