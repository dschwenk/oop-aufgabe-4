// OOP-Aufgabe-4.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdlib.h"
#include <iostream>
#include <string>
#include "medium.h"
#include "buch.h"
#include "video.h"
#include "container.h"
#include "exceptions.h"

using namespace std;


int main(){

	// Container, der die Medien listet / verwaltet
	Container container;
	
	// benoetigt fuer Menuauswahl
	char inputChoice = '\0';
	
	// benoetigt fuer Auswahl Medium entleihen / zurueck geben
	int inputSignatur = 0;

	// benoetigt um zu pruefen ob Medium mit der Signatur vorhanden ist
	bool Signaturvorhanden;

	while(true){
		cout << "Was wollen Sie tun?\n";
		cout << "b - Buch anlegen\n";
		cout << "v - Video anlegen\n";
		cout << "l - Medieneigenschaften ausgeben\n";
		cout << "e Signatur - Medium entleihen\n";
		cout << "r Signatur - Rueckgabe\n";
		cout << "d Signatur - Medium entfernen\n";
		cout << "q - Programmende\n";
		cout << "Auswahl: ";

		cin >> inputChoice;

		switch(inputChoice){
			// neues Buch
			case 'b':
				// neues Buch anelgen und zur Liste hinzufuegen
				Buch* tmpBuch;
				tmpBuch = new Buch();
				Signaturvorhanden = false;
				// setzte Iterator auf erstes Element der Liste, gehe dann Liste durch und pruefe ob Medium mit entsprechender Signatur vorhanden
				for(container.begin();container.getitem() != NULL;container.next()){
					if(container.getitem()->getSignatur() == tmpBuch->getSignatur()){
						Signaturvorhanden = true;
						break;
					}
				}
				if(Signaturvorhanden){
					cout << "\nBuch konnte nicht angelegt werden, da bereits ein Medium mit der Signatur " << tmpBuch->getSignatur() << " vorhanden ist.\n\n";
				}
				else {
					container.add(tmpBuch);
					cout << "\nBuch angelegt und zur Liste hinzugefuegt.\n\n";
				}
				break;
			// neues Video
			case 'v':
				// neues Video anelgen und zur Liste hinzufuegen
				Video* tmpVideo;
				tmpVideo = new Video();
				Signaturvorhanden = false;
				// setzte Iterator auf erstes Element der Liste, gehe dann Liste durch und pruefe ob Medium mit entsprechender Signatur vorhanden
				for(container.begin();container.getitem() != NULL;container.next()){
					if(container.getitem()->getSignatur() == tmpVideo->getSignatur()){
						Signaturvorhanden = true;
						break;
					}
				}
				if(Signaturvorhanden){
					cout << "\nVideo konnte nicht angelegt werden, da bereits ein Medium mit der Signatur " << tmpVideo->getSignatur() << " vorhanden ist.\n\n";
				}
				else {
					container.add(tmpVideo);
					cout << "\nVideo angelegt und zur Liste hinzugefuegt.\n\n";
				}		
				break;
			// auflisten
			case 'l':
				// setzte Iterator auf erstes Element der Liste
				container.begin();
				// sind Medien vorhanden?
				if(container.getitem() != NULL){
					// Tabelle Kopfzeile ausgeben
					Medium::printHeadline();
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
			// entleihen
			case 'e':
				cin >> inputSignatur;
				Signaturvorhanden = false;
				container.begin();
				// sind Medien vorhanden?
				if(container.getitem() != NULL){
					// gehe Liste durch und pruefe ob Medium mit entsprechender Signatur vorhanden
					for(container.begin();container.getitem() != NULL;container.next()){					
						if(container.getitem()->getSignatur() == inputSignatur){
							Signaturvorhanden = true;
							break;
						}
					}
					// Medium mit Signatur vorhanden
					if(Signaturvorhanden){
						try {
							container.getitem()->ausleihen();
							break;
						}
						catch(StatusError err){
							cout << "\n" << err.messages() << "\n";
						}
					}
					// Medium mit Signatur NICHT vorhanden
					else {
						cout << "\nKein Medium mit der Signatur " << inputSignatur << " vorhanden.\n\n";
					}					
				}
				else {
					cout << "\nKeine Medien vorhanden.\n\n";
				}
				break;
			// Rueckgabe
			case 'r':
				cin >> inputSignatur;
				Signaturvorhanden = false;
				container.begin();
				// sind Medien vorhanden?
				if(container.getitem() != NULL){
					// gehe Liste durch und pruefe ob Medium mit entsprechender Signatur vorhanden
					for(container.begin();container.getitem() != NULL;container.next()){					
						if(container.getitem()->getSignatur() == inputSignatur){
							Signaturvorhanden = true;
							break;
						}
					}
					// Medium mit Signatur vorhanden
					if(Signaturvorhanden){
						try {
							container.getitem()->rueckgabe();
							break;
						}
						catch(StatusError err){
							cout << "\n" << err.messages() << "\n";
						}
					}
					// Medium mit Signatur NICHT vorhanden
					else {
						cout << "\nKein Medium mit der Signatur " << inputSignatur << " vorhanden.\n\n";
					}					
				}
				else {
					cout << "\nKeine Medien vorhanden.\n\n";
				}
				break;
			// Medium entfernen
			case 'd':
				cin >> inputSignatur;
				Signaturvorhanden = false;
				container.begin();
				// sind Medien vorhanden?
				if(container.getitem() != NULL){
					// gehe Liste durch und pruefe ob Medium mit entsprechender Signatur vorhanden
					for(container.begin();container.getitem() != NULL;container.next()){					
						if(container.getitem()->getSignatur() == inputSignatur){
							Signaturvorhanden = true;
							break;
						}
					}
					// Medium mit Signatur vorhanden
					if(Signaturvorhanden){
						if(container.remove()){
							cout << "\nMedium geloescht.\n\n";
							break;
						}
						else {
							cout << "\n" << "\nFehler beim Loeschen.\n\n";
							break;
						}
					}
					// Medium mit Signatur NICHT vorhanden
					else {
						cout << "\nKein Medium mit der Signatur " << inputSignatur << " vorhanden.\n\n";
					}
				}
				else {
					cout << "\nKeine Medien vorhanden.\n\n";
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