#include <iostream>
#include <fstream>
#include "funksjoner.h"
#include "steder.h"
#include "sone.h"



using namespace std;


Sone::Sone()
{
	soneListe = new List(Sorted);
}


void Sone::meny()
{
	char kommando = 'E';

	kommando = les();

	switch (kommando) {
	case 'D': displayOppsett(); break;
	case 'N': nyttOppsett(); break;
	case 'E': cout << "Endre oppsett funksjon kommer"; break;
	}
}

void Sone::nyttOppsett() {

}

void Sone::displayOppsett() {

}

