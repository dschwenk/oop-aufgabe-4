#include "stdlib.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "medium.h"
#include "video.h"

using namespace std;


Video::Video():Medium(false){
	// Signatur, Spieldauer, Titel einlesen
	cout << "\nBitte Mediendaten eingeben: Signatur, Spieldauer, Titel\n";	
	do {
		cin.clear();
		cin.sync();
		cout << "Signatur: ";
	}
	while(!(cin >> this->signatur));

	do {
		cin.clear();
		cin.sync();
		cout << "Spieldauer: ";
	}
	while(!(cin >> this->spieldauer));
	
	cout << "Titel: ";
	cin.sync();	
	getline(cin,this->titel);

	cout << "\nVideo angelegt.\n\n";
}


void Video::print(){
	cout << right << setw(8) << signatur << "  " << left << setw(8) << "Video" << setw(18) << titel << "  " << setw(8);
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
	cout << right << "Dauer " << right << fixed << setprecision(2) << this->spieldauer << " min\n";
}