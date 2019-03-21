#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include "sted.h"
#include "steder.h"
#include "ListTool2B.h"
#include "stoler.h"
#include "vrimle.h"
#include <cstring>
#include "const.h"
#include <iostream>
#include <fstream>

using namespace std;





Sted::Sted(char t[]) : TextElement(t)  //	"t" sendes til TextElement
{
	stednavn = new char[strlen(t) + 1]; strcpy(stednavn, t);
};


void Sted::display() {

	cout << "Navn paa spillested: " << stednavn;
}

void Sted::skrivTilFilSted(ofstream & utfil) {
	
	utfil << stednavn << "\n";
}

void Sted::nyVrimle(char * t, int i) {

	
	oppsett[i]->add(new Vrimle(t));
	cout << "nyVrimle funksjon\n";
	
	
}

void Sted::nyStoler(char *t)  {

}

int Sted::hentOppsett() {
	
	int i;
	for (i = 1; i <= 5; i++) {
		if (oppsett[i] == nullptr) { 
			oppsett[i] = new List(Sorted);
			return i; 
			
		}
	}
	
	

	return 0;
}

#endif