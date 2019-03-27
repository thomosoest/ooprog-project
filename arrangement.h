#ifndef __ARRANGEMENT_H
#define __ARRANGEMENT_H

#include "ListTool2B.h"
#include <fstream>
#include "const.h"

using namespace std;

class Arrangement : public TextElement {

private:

	char* arrangementnavn;
	char* spillested;	//Navn p� stedet arrangementet befinner seg
	char* artist;
	Typearrangement type;
	int arrangementNr; //skal v�re unikt
	int dato;
	int minutt;
	int time;


public:

	Arrangement(char t[], char a[], int n);
	Arrangement(char t[], ifstream & innfil);
	void display();
	void skrivFil();

	bool riktigSted(char* nvn);
};

#endif