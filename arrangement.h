#ifndef __ARRANGEMENT_H
#define __ARRANGEMENT_H

#include "ListTool2B.h"
#include <fstream>


using namespace std;

class Arrangement : public TextElement {

private:

	char* arrangementnavn;
	char* spillested;	//Navn på stedet arrangementet befinner seg
	char* artist;

	int arrangementNr; //skal være unikt
	int dato;
	int minutt;
	int time;


public:

	Arrangement(char t[], char a[], int n);
	
	void display();
	void skrivFil();

	bool riktigSted(char* nvn);
};

#endif