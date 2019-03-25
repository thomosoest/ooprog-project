#ifndef __SONE_H
#define __SONE_H

#include "sone.h"
#include <iostream>
#include "const.h"

using namespace std;



class Stoler : public Sone {
private:
	int kundenr; //Kundenr til de som har kjopt billetter
	int sete[RAD][REKKE];
	int rad, rekke;
	
public:
	 void display();
	 Stoler(char * t);
};
#endif
