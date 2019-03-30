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
	Arrangement(char t[], ifstream & innfil);
	void skrivFil(ofstream & utfil);

	void display();
	void tekstSjekk(char* navn);
	void stedSjekk(char* navn);
	void datoSjekk(int n);
	void typeSjekk();
	void artistSjekk(char* navn);
	void billettUtskrift();
	void lesData(List * l, char t[]);
	void displayType();
	
};

#endif