#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <fstream>
#include "funksjoner.h"
#include "steder.h"
#include "sone.h"



using namespace std;


Sone::Sone()
{
	cout << "Skal ikke ha tomme constructorer i sone";
}

Sone::Sone(char * t) : TextElement(t) {


	pris = lesTall("Billettpris", 1, 2500);
	antBill = lesTall("Antall totalt", 1, 4000);


}



void Sone::nyttOppsett() {

}

void Sone::displayOppsett() {

}

#endif