#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS



#include "kunde.h"
#include "ListTool2B.h"
#include <cstring>

#include "const.h"
#include <iostream>

using namespace std;

Kunde::Kunde(int n) : NumElement(n)  //	"n" sendes til NumElement
{
	char buf[STRLEN];
	

	cout << "Kundens navn: ";  cin.getline(buf, STRLEN);
	navn = new char[strlen(buf) + 1]; strcpy(navn, buf);
	cout << "Du har nå lagt til ny kunde." << endl;


};



void Kunde::display()
{
	cout << "\t navn: " << navn << '\n';

};


#endif