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
	bool foundSignatur = false;

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
				container.add(new Buch());
				break;
			// neues Video
			case 'v':
				// neues Video anelgen und zur Liste hinzufuegen
				container.add(new Video());				
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
				// setzte Iterator auf erstes Element der Liste
				container.begin();
				// sind Medien vorhanden?
				if(container.getitem() != NULL){
					if(container.getitem()->getSignatur() == inputSignatur){
						try {
							container.getitem()->ausleihen();
						}
						catch(StatusError err){
							cout << err.messages() << "\n\n";
						}
					}
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
				// setzte Iterator auf erstes Element der Liste
				container.begin();
				// sind Medien vorhanden?
				if(container.getitem() != NULL){
					if(container.getitem()->getSignatur() == inputSignatur){
						try {
							container.getitem()->rueckgabe();
						}
						catch(StatusError err){
							cout << "\n" << err.messages() << "\n";
						}
					}
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
				// setzte Iterator auf erstes Element der Liste, gehe dann Liste durch und pruefe ob Medium mit entsprechender Signatur vorhanden
				for(container.begin();container.getitem() != NULL;container.next()){
					if(container.getitem()->getSignatur() == inputSignatur){
						if(container.remove()){
							cout << "\nMedium geloescht.\n\n";
							break;
						}
						else {
							cout << "\n" << "\nFehler beim Loeschen.\n\n";
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