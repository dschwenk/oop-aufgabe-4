#include "stdlib.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "medium.h"
#include "buch.h"

using namespace std;


Buch::Buch():Medium(false){
	// Signatur, Seitenzahl, Titel einlesen
	cout << "\nBitte Mediendaten eingeben: Signatur, Seitenzahl, Titel\n";
	do {
		// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
		cin.clear();
		cin.sync();
		cout << "Signatur: ";
	}
	while(!(cin >> this->signatur));

	do {
		cin.clear();
		cin.sync();
		cout << "Seitenzahl: ";
	}
	while(!(cin >> this->seitenzahl));

	cout << "Titel: ";
	cin.sync();
	getline(cin,this->titel);

	cout << "\nBuch angelegt.\n\n";
}



void Buch::print(){
	cout << right << setw(8) << signatur << "  " << left << setw(8) << "Buch" << "  ";
	if(this->titel.size() > 15){
		string cutTitel = titel.substr(0,15);
		cutTitel = cutTitel + "...";
		cout << setw(18) << cutTitel << "  " << left << setw(8);
	}
	else {
		cout << setw(18) << titel << "  " << left << setw(8);
	}	
	if(this->status == entliehen){
		cout << "entl.";
	}
	else {
		cout << "vorh.";
	}
	cout << "  " << right << "Seitenanzahl " << left << this->seitenzahl << "\n";
}