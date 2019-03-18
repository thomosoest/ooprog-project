#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS


#include "sted.h"
#include "steder.h"
#include "ListTool2B.h"
#include <cstring>
#include "const.h"
#include <iostream>

using namespace std;





Sted::Sted(char t[]) : TextElement(t)  //	"t" sendes til TextElement
{
	stednavn = new char[strlen(t) + 1]; strcpy(stednavn, t);
};


void Sted::display() {

	cout << "Navn paa spillested: " << stednavn;
}

#endif