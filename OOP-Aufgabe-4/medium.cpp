#include "stdlib.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "medium.h"
#include "exceptions.h"

using namespace std;


Medium::Medium() {
	// Signatur + Titel einlesen
	cout << "\nBitte Mediendaten eingeben: Signatur, Titel\n";
	do {
		// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
		cin.clear();
		cin.sync();
		cout << "Signatur: ";
	}
	while(!(cin >> this->signatur));
	
	cout << "Titel: ";
	cin.sync();
	getline(cin,this->titel);

	this->status = vorhanden;

	cout << "\nMedium angelegt.\n\n";
}

Medium::Medium(bool b){
	// Signatur + Titel etc in Buch- / Video-Konstruktor
	this->status = vorhanden;
}

Medium::~Medium(){
	cout << "\nKontruktor des Mediums mit der Signatur: " << this->signatur << "\n";
}


const void Medium::printHeadline(){
	// gebe Tabellenkopf
	cout << setw(8) << "Signatur" << left << setw(8)  << "Typ" << setw(18) << "Titel" << left << setw(10) << "Status" << setw(20) << "weitere Daten" << "\n";
}

void Medium::print(){
	cout << right << setw(8) << signatur << "  " << left << setw(8) << "Medium";
	// schneide Titel ab falls dieser laenger als 15 Zeichen ist, ersetze durch Punkte
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
	cout << "\n";
}


void Medium::ausleihen(){
	// pruefen ob bereits ausgeliehen
	if(this->status == entliehen){
		throw StatusError(this->signatur, 0);
	}
	else {
		this->status = entliehen;
		cout << "\nMedium entliehen.\n\n";
	}
}


void Medium::rueckgabe(){
	// // pruefen ob ueberhaupt ausgeliehen
	if(this->status == entliehen){
		this->status = vorhanden;
		cout << "\nMedium zurueckgegeben.\n\n";
	}
	else {
		throw StatusError(signatur, 1);
	}
}


int Medium::getSignatur(){
	return this->signatur;
}