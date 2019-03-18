#ifndef __SONER_H
#define __SONER_H
class Sone {
private:

	List * soneListe;
	char * sonenavn; //Unikt sonenavn
	int antBill, antSolgt, pris; //Antall billetter til salgs, Antall solgt og pris
public:
	//virtual void display();
	void meny();
	void displayOppsett();
	void nyttOppsett();
	Sone();
};

#endif