#ifndef __CONST_H
#define __CONST_H

const int STRLEN = 100;		//Maks string lengde
const int OPS = 5;			//Oppsett
const int ANTVRIMLE = 100;  //Maks antall i Vrimle sonen
int const RAD = 200;		//I stoler
int const REKKE = 200;		//I stoler
int const MAXBILLETTER = 5;	

		
								//Tid, sted, tlf og dato const'er:
int const TIMEMAX = 24;
int const TIMEMIN = 00;
int const MINUTTMAX = 59;
int const MINUTTMIN = 00;
int const POSTMIN = 0000;
int const POSTMAX = 9999;
int const TLFMIN = 10000000;
int const TLFMAX = 99999999;
int const DATOMIN = 010101;
int const DATOMAX = 991232;
int const MAXTYPE = 7;


enum Typearrangement				//Arrangementenes typer
{	
	tom,							//Tom for aa hjelpe ifstream lese opp			
	musikk,				
	sport,
	teater,
	show,
	kino,
	familie,
	festival,
};


#endif