#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cctype>
#include "funksjoner.h"
#include "steder.h"
#include "sted.h"
#include "ListTool2B.h"



using namespace std;


Steder::Steder(){
	stedListe = new List(Sorted); //lager ny liste med steder
}

void Steder::meny(char valg)
{
	if (valg == 'S') {					//Om 'S' er skrevet
		char kommando = les();			//leser inn paafolgende char i konsollvindu
		switch (kommando) {				
		case 'D': displaySted(); break;	//kaller paa displayfunksjon for sted
		case 'N': nyttSted(); break;	//kaller paa funksjon for aa lage nytt sted
		}
	}
	else if (valg == 'O') {
		
		char kommando = les();
		switch (kommando) {
		case 'D': displayOppsett();	break;	//Kaller paa displayfunksjon for oppsett
		case 'N': nyttOppsett(); break;		//kaller paa funksjon for aa lage nytt oppsett
		case 'E': endreOppsett();  break;
		}
	}
	}

void Steder::nyttSted() { //Legger til ett nytt sted i stedListe

	char nvn[STRLEN];

	do {
		lesTekst("Navn paa sted", nvn, STRLEN);
		if (stedListe->inList(nvn)) cout << "Stedsnavn finnes allerede"; 
	} while (strlen(nvn) == 0 || stedListe->inList(nvn) == true); //Looper om ugyldig stedsnavn

	stedListe->add(new Sted(nvn)); //kaller paa sted constructor og sender med stedsnavn
}

void Steder::displaySted() { //displayfunksjon for stedListe
	
	stedListe->displayList();
}

void Steder::lesFraFil() {
	ifstream innfil ("STEDER.DTA");
	int totSteder;
	char navnsted[STRLEN];
	if (innfil) {
		innfil >> totSteder;
		for (int i = 1; i <= totSteder; i++) {
			innfil >> navnsted;
			stedListe->add(new Sted(navnsted, innfil));
		}
	}
	else cout << "\n\t\tFinner ikke fil med steder: STEDER.DTA\n\n";	
}

void Steder::skrivTilFil() {
	ofstream utfil ("STEDER.DTA");
	
	Sted * temp;
	utfil << stedListe->noOfElements() << "\n";

	for (int i = 1; i <= stedListe->noOfElements(); i++) {
		temp = (Sted*) stedListe->removeNo(i);
		temp->skrivTilFilSted(utfil);
		stedListe->add(temp);
	}
}

void Steder::nyttOppsett() {
	char  arr[STRLEN];
	Sted * peker;
	char svar;
	char buff[STRLEN];
	char * sonenavn;
	int ops;
	
	do {
		lesTekst("Stednavn: ", arr, STRLEN);
		if (!stedListe->inList(arr))
			cout << "Ugyldig stedsnavn";
	} while (!stedListe->inList(arr));
	
	do {
		cout << "Vil du opprette: \n\t(E)tt helt nytt oppsett \n\t(K)opiere oppsett fra annet og endre paa\n";
		cin >> svar;
		toupper(svar);
	} while (svar != 'E' && svar != 'K');
	
	peker = (Sted*)stedListe->remove(arr); //tar ut sted fra listen
	   
	if (svar == 'E') {							//Om velger aa lage ett helt nytt oppsett
		if (peker->hentNrOppsett() <= OPS-1) {							
			ops = peker->lagNyttOppsettListe(); //lager ett nytt oppsett
			cout << "\nOppsett nummer: " << ops; 
			do {
				lesTekst("Skriv inn sonenavn ('q' for aa avslutte): ", buff, STRLEN);
				sonenavn = new char[strlen(buff) + 1]; strcpy(sonenavn, buff);
				if (*sonenavn != 'q') {							//Looper til bruker taster 'q'
					cout << "Sonetype: (S)toler / (V)rimle: ";
					cin >> svar;
					toupper(svar);
					if (svar == 'S') peker->nyStoler(sonenavn, ops);			//lager nytt stolerobjekt
					else if (svar == 'V') peker->nyVrimle(sonenavn, ops);		//lager nytt vrimleobjekt
				}
			} while (*sonenavn != 'q');
			peker->sisteOppsettPlussEn(); //Legger til en paa sisteOppsett.
		}
		else cout << "For mange oppsett";
	}
	else if (svar == 'K'){		//Om velger aa kopiere ett oppsett
		char * frasted;			//Sted man kopierer fra
		int oppsettnr;			//nr paa oppsett man kopierer fra
		char buff[STRLEN];
		peker->hentNrOppsett(); //Oppdaterer sisteBrukt av oppsett
		lesTekst("Hvilket sted vil du kopiere fra: ", buff, STRLEN);
		frasted = new char[strlen(buff) + 1]; strcpy(frasted, buff);
		cout << "Hvilket oppsett vil du kopiere?";
		cin >> oppsettnr;
		peker->kopiOppsett(kopier(frasted, oppsettnr)); //sender listen kopier returnerer til kopioppsett
	}
	stedListe->add(peker);				//legger tilbake stedobjekt til listen
}


void Steder::displayOppsett() { //Display funksjon for oppsett

	Sted * peker;		//for aa kalle paa funksjoner i Sted
	char arr[STRLEN];	//navn paa sted 
	int svar;			//hvilket oppsett som skal bli vist

	do {
		lesTekst("Stednavn: ", arr, STRLEN);
		if (!stedListe->inList(arr))
			cout << "Ugyldig stedsnavn";
	} while (!stedListe->inList(arr));
	
	peker = (Sted*)stedListe->remove(arr);		//tar sted ut fra listen

	svar = lesTall("Hvilket stoloppsett vil du se: ", 1, peker->hentNrOppsett()); //Mellom 1 - sist brukte oppsett
	peker->displayOppsett(svar); //Kaller paa displayfunksjon i sted
	
	stedListe->add(peker);						//legger sted tilbake i listen
}

List* Steder::kopier(char* nvn, int nr) { //Kopiert fra frode
	List* liste = NULL;
	Sted* sted;

	if ((sted = (Sted*)stedListe->remove(nvn))) {
		liste = sted->kopier(nr);
		stedListe->add(sted);
	}
	return liste;
}

bool Steder::finnesStedOgOps(char * nvn, int i) { //tar inn stednavn som parameter og returner true eller false
	Sted * sted;
	if ((Sted*)stedListe->inList(nvn)) {
		sted = (Sted*)stedListe->remove(nvn);
		stedListe->add(sted);
		if (i <= sted->hentNrOppsett())
			return true;
	}
		return false;
}

void Steder::endreOppsett() {

	Sted * peker;		//for aa kalle paa funksjoner i Sted
	char arr[STRLEN];
	int ops;

	do {										//saa lenge gyldig stedsnavn
		lesTekst("Stednavn: ", arr, STRLEN);
		if (stedListe->inList(arr) != true)
			cout << "Ugyldig stedsnavn";
	} while (stedListe->inList(arr) != true);

	
	peker = (Sted*)stedListe->remove(arr);		//tar sted ut fra listen
	ops = lesTall("Oppsettnummer: ", 1, peker->hentNrOppsett()); //leser inn oppsettnr
	peker->endreOppsett(ops);									 //kaller paa endreoppsett i sted
	(Sted*)stedListe->add(peker);			    //Legger sted tilbake i listen
}

#endif