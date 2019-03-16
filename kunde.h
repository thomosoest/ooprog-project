#ifndef __KUNDE_H
#define __KUNDE_H

#include "ListTool2B.h"

class Kunde : public NumElement{

private:

	char* navn;

public:

	Kunde(int n);
	void display();

};
#endif

