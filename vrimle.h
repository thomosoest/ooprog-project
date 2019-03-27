#ifndef __Sone_H
#define __Sone_H

#include "funksjoner.h"
#include "sone.h"
#include "const.h"

class Vrimle : public Sone {
private:
	int kundenr[ANTVRIMLE]; //Kundenr til de som har kjopt billetter
	char type;
public:
	void display();
	Vrimle(char * t);
	Vrimle(Vrimle & v);
};
#endif
