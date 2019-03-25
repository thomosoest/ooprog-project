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

	cout << "Stoler constructor\n";

	rad = lesTall("Hvor mange rader: ", 1, RAD);
	rekke = lesTall("Hvor mange rekker: ", 1, REKKE);

	sete[RAD][REKKE] = sete[rad][rekke];
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

#endif