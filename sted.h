
#ifndef __STED_H
#define __STED_H

#include "ListTool2B.h"
#include "const.h"
#include <iostream>
#include <fstream>

using namespace std;

class Sted : public TextElement {

private:

	char * stednavn;
	List * oppsett[OPS];
	

public:

	Sted(char t[]);
	void display();
	void skrivTilFilSted(ofstream & utfil);
	void nyVrimle(char *t, int i);
	void nyStoler(char *t, int i);
	int hentOppsett();
	void displayOppsett(int i);
	

};
#endif



