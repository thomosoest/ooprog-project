#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "funksjoner.h"
#include "steder.h"
#include "sted.h"
#include "stoler.h"
#include "ListTool2B.h"




using namespace std;


Stoler::Stoler(char *t) : Sone(t) {

	cout << "Stoler constructor\n";
	
	int rad, rekke;

	rad = lesTall("Hvor mange rader: ", 1, RAD);
	rekke = lesTall("Hvor mange rekker: ", 1, REKKE);

	sete[RAD][REKKE] = sete[rad][rekke];
}

void Stoler::display() {
	cout << "Stolerdisplay";
}

#endif