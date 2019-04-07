#ifndef __ARRANGEMENT_H
#define __ARRANGEMENT_H

#include "ListTool2B.h"
#include <fstream>
#include "const.h"

using namespace std;

class Arrangement : public TextElement {

private:

	char* spillested;	//Navn på stedet arrangementet befinner seg
	char* artist;
	enum Typearrangement type;
	int arrangementNr; //skal være unikt
	int dato;
	int minutt;
	int time;
	List * oppsett;

public:

	Arrangement(char t[], int n);
	Arrangement(char[STRLEN],ifstream & innfil);
	void skrivFil(ofstream & utfil);

	void display();
	void endreArrangement();
	void lesType();

	void billettKjop();
	bool tekstSjekk(char* navn);			//Display funksjoner
	bool stedSjekk(char* navn);
	bool datoSjekk(int n);
	bool typeSjekk(int n);
	bool artistSjekk(char* navn);
	bool billettUtskrift(int n);

	void lesOppsettFraFil();
	void lesData(List * l, char t[]);
	void skrivBilletter(ofstream & utfil,int knr);
	void displayType();
	void skrivTilFil();
	int hentnr();
};

#endif