
#ifndef __STED_H
#define __STED_H

#include "ListTool2B.h"
#include "const.h"

class Sted : public TextElement {

private:

	char* stednavn;
	int Oppsett[OPS]; //Antall oppsett

public:

	Sted(char* t);
	void display();
	

};
#endif



