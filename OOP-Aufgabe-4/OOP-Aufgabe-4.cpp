// OOP-Aufgabe-4.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdlib.h"
#include <iostream>
#include <string>
#include "medium.h"
#include "buch.h"
#include "video.h"

#include "container.h"

using namespace std;


int main(){

	// Container, der die Medien listet / verwaltet
	Container container;

	Medium* tmpMedium;
	
	// benoetigt fuer Menuauswahl
	char inputChoice = '\0';
	
	// benoetigt fuer Auswahl Medium entleihen / zurueck geben
	int inputSignatur = 0;
	bool foundSignatur = false;

	while(true){
		cout << "Was wollen Sie tun?\n";
		cout <<	"m - Medium anlegen\n";
		// cout << "b - Buch anlegen\n";
		// cout << "v - Video anlegen\n";
		cout << "l - Medieneigenschaften ausgeben\n";
		// cout << "e - Medium entleihen\n";
		// cout << "r - Rueckgabe\n";
		cout << "d Signatur - Medium entfernen\n";
		cout << "q - Programmende\n";
		cout << "Auswahl: ";

		cin >> inputChoice;

		switch(inputChoice){
			/*
			// neues Buch
			case 'b':
				if(AnzahlBuecher < MAXANZAHLMEDIEN){
					BuchArray[AnzahlBuecher] = new Buch();
					AnzahlBuecher++;
				}
				else {
					cout << "\nMaximal Anzahl an Buecher erreicht!\n\n";
				}
				break;
			*/
			// neues Medium
			case 'm':
				// neues Medium anelgen und zur Liste hinzufuegen
				tmpMedium = new Medium();
				container.add(tmpMedium);				
				break;
			/*
			// neues Video
			case 'v':
				if(AnzahlVideos < MAXANZAHLMEDIEN){
					VideoArray[AnzahlVideos] = new Video();
					AnzahlVideos++;
				}
				else {
					cout << "\nMaximal Anzahl an Videos erreicht!\n\n";
				}
				break;
			*/
			// auflisten
			case 'l':
				// setzte Iterator auf erstes Element der Liste
				container.begin();
				// sind Medien vorhanden?
				if(container.getitem() != NULL){
					cout << "\nMedienbestand: \n";
					do {
						// Ausgabe
						container.getitem()->print();
						// setzte Iterator auf naechstes Element
						container.next();
					}
					while(container.getitem() != NULL);
					cout << "\n";
				}
				else {
					cout << "\nKeine Medien vorhanden.\n\n";
				}				
				break;
			/*
			// entleihen
			case 'e':
				// sind Medien vorhanden?
				if((AnzahlMedien != 0) || (AnzahlBuecher != 0) || (AnzahlVideos != 0)){
					cout << "\nWelches Medium wollen Sie entleihen? Geben Sie bitte die zugehoerige Signatur ein.\n";
					do {
						cin.clear();
						cin.sync();
						cout << "Signatur: ";
					}
					while(!(cin >> inputSignatur) && cin.fail());
					foundSignatur = false;
					// Medium mit passender Signatur vorhanden?					
					for(int i=0;i<AnzahlMedien;i++){
						if(MediumArray[i]->getSignatur() == inputSignatur){
							MediumArray[i]->ausleihen();
							foundSignatur = true;
							break;
						}
					}
					for(int i=0;i<AnzahlBuecher;i++){
						if(BuchArray[i]->getSignatur() == inputSignatur){
							BuchArray[i]->ausleihen();
							foundSignatur = true;
							break;
						}
					}
					for(int i=0;i<AnzahlVideos;i++){
						if(VideoArray[i]->getSignatur() == inputSignatur){
							VideoArray[i]->ausleihen();
							foundSignatur = true;
							break;
						}
					}
					// kein passendes Medium zur Signatur gefunden
					if(!foundSignatur){
						cout << "\nKein Medium mit der Signatur " << inputSignatur << " vorhanden.\n\n";
					}
				}
				else {
					cout << "\nKeine Medien vorhanden.\n\n";
				}
				break;
			*/
			/*
			// Rueckgabe
			case 'r':
				// sind Medien vorhanden?
				if((AnzahlMedien != 0) || (AnzahlBuecher != 0) || (AnzahlVideos != 0)){
					cout << "\nWelches Medium wollen Sie zurueck geben? Geben Sie bitte die zugehoerige Signatur ein.\n";
					do {
						cin.clear();
						cin.sync();
						cout << "Signatur: ";
					}
					while(!(cin >> inputSignatur) && cin.fail());
					foundSignatur = false;					
					// Medium mit passender Signatur vorhanden?
					for(int i=0;i<AnzahlMedien;i++){
						if(MediumArray[i]->getSignatur() == inputSignatur){
							MediumArray[i]->rueckgabe();
							foundSignatur = true;
							break;
						}
					}
					for(int i=0;i<AnzahlBuecher;i++){
						if(BuchArray[i]->getSignatur() == inputSignatur){
							BuchArray[i]->rueckgabe();
							foundSignatur = true;
							break;
						}
					}
					for(int i=0;i<AnzahlVideos;i++){
						if(VideoArray[i]->getSignatur() == inputSignatur){
							VideoArray[i]->rueckgabe();
							foundSignatur = true;
							break;
						}
					}
					if(!foundSignatur){
						cout << "\nKein Medium mit der Signatur " << inputSignatur << " vorhanden.\n\n";
					}
				}
				else {
					cout << "\nKeine Medien vorhanden.\n\n";
				}
				break;
			*/
			// Medium entfernen
			case 'd':
				cin >> inputSignatur;
				// setzte Iterator auf erstes Element der Liste, gehe dann Liste durch und pruefe ob Medium mit entsprechender Signatur vorhanden
				for(container.begin();container.getitem() != NULL;container.next()){
					if(container.getitem()->getSignatur() == inputSignatur){
						if(container.remove()){
							cout << "\nMedium geloescht.\n\n";
							break;
						}
						else {
							cout << "\nFehler beim Loeschen.\n\n";
							break;
						}
					}
				}
				break;
			// Verlassen
			case 'q':
				// setzte Iterator auf erstes Element der Liste, gehe dann Liste durch und loesche die Elemente nach einandern
				container.begin();
				while(container.getitem() != NULL){
					container.remove();
					container.begin();
				}
				return 0;
			default:
				cout << "\nUngueltige Eingabe!\n\n";
		}
	}
}