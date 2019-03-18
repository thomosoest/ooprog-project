#include <iostream>
#include "funksjoner.h"

using namespace std;

//  Leser og upcaser ett tegn:
char les() {
	char ch;
	cout << "\n";   cin >> ch;   cin.ignore();
	return (toupper(ch));
}

//  Leser et tall mellom MIN og MAX:
int lesTall(const char t[], const int MIN, const int MAX) {
	int n;
	do {
		cout << '\t' << t << " (" << MIN << '-' << MAX << "): ";
		cin >> n;  cin.ignore();
	} while (n < MIN || n > MAX);
	return n;
}

//  Leser inn en ikke-blank tekst:
void lesTekst(const char t[], char s[], const int LEN) {
	do {
		cout << '\t' << t << ": ";	//  Skriver ledetekst.
		cin.getline(s, LEN);        //  Leser inn tekst.
	} while (strlen(s) == 0);     //  Sjekker at tekstlengden er ulik 0.
}

//  Leser inn en tekst (til og med blank)
void lesTekstBlank(const char t[], char s[], const int LEN) {
	cout << '\t' << t << ": ";	//  Skriver ledetekst.
	cin.getline(s, LEN);        //  Leser inn tekst.
}

