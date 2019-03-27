#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "funksjoner.h"
#include "steder.h"
#include "sted.h"
#include "stoler.h"
#include "ListTool2B.h"
#include "sone.h"




using namespace std;


Stoler::Stoler(char *t) : Sone(t) {

	rad = lesTall("Hvor mange rader: ", 1, RAD);
	rekke = lesTall("Hvor mange rekker: ", 1, REKKE);

	sete[RAD][REKKE] = sete[rad][rekke];

	type = 'S';
}

void Stoler::display() {
	
	Sone::display();

	for (int i = 1; i <= rad; i++) {
		cout << "\n0 ";
		for (int j = 1; j <= rekke; j++) {
			cout << " 0 ";
		}
	}
}

Stoler::Stoler(Stoler & s) : Sone((Sone*)&s) { //kopiert fra frode
	//int i, j;

	rad = s.rad;
	rekke = s.rekke;

	/*
	billett = new int*[rad + 1];
	for (i = 1; i <= rad; i++)
		billett[i] = new int[rekke + 1];

	for (i = 1; i <= rad; i++)
		for (j = 1; j <= rekke; j++)
			billett[i][j] = 0;
			*/
}
#endif