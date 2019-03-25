#ifndef __ARRANGEMENTER_H
#define __ARRANGEMENTER_H


#include "ListTool2B.h"
#include "arrangement.h"


class Arrangementer {



private:

	int sisteArrangement;
	List * arrangementListe;

public:


	Arrangementer();
	void nyArrangement();
	void meny();
	void displayArrangement();
	// void endreArrangement();
	void slettArrangement();
	void kjopBillett();

	//void lesFil();
};


#endif 
