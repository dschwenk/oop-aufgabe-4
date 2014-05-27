#include "stdlib.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "medium.h"

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

	this->entliehen = false;

	cout << "\nMedium angelegt.\n\n";
}

Medium::Medium(bool b){
	// Signatur + Titel etc in Buch- / Video-Konstruktor
	this->entliehen = false;
}

Medium::~Medium(){
	cout << "\nKontruktor des Mediums mit der Signatur: " << this->signatur << "\n";
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
	if(this->entliehen){
		cout << "entl.";
	}
	else {
		cout << "vorh.";
	}
	cout << "\n";
}


void Medium::ausleihen(){
	// pruefen ob bereits ausgeliehen
	if(this->entliehen){
		cout << "\nMedium bereits ausgeliehen!\n\n";
	}
	else {
		this->entliehen = true;
		cout << "\nMedium ausgeliehen.\n\n";
	}
}


void Medium::rueckgabe(){
	// // pruefen ob ueberhaupt ausgeliehen
	if(this->entliehen){
		this->entliehen = false;
		cout << "\nMedium zurueckgegeben.\n\n";
	}
	else {
		cout << "\nMedium nicht ausgeliehen.\n\n";
	}
}


int Medium::getSignatur(){
	return this->signatur;
}


bool Medium::getAvailable(){
	return this->entliehen;
}