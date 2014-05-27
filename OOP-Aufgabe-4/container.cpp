#include "stdlib.h"
#include "container.h"

using namespace std;


Knoten::Knoten(Knoten* next, T* item){
	// neuen Knoten initialisieren -> zeige auf naechsten Knoten und auf das Element (Medium)
	this->next = next;
	this->item = item;
}


Container::Container(){
	// Container initialisieren -> es sind keine Elemente vorhanden -> first & iterator = NULL
	this->first = NULL;
	this->iterator = NULL;
}


void Container::add(T *element) {
	
	// neuen Knoten anlegen
	Knoten* tmpKnoten = new Knoten(this->first,element);

	// sind keine Knoten in der Liste, setze iterator auf neues Element
	if(this->first == NULL){
		this->iterator = tmpKnoten;
	}
	// neuer Knoten wird vorne in der List eingefuegt
	this->first = tmpKnoten;
}


bool Container::remove() {
	// pruefe ob Element(e) in der Liste
	if (this->iterator == NULL){
		return false;
	}

	Knoten* tmpKnoten = first;
	// Iterator zeigt auf erstes Element
	if(this->iterator == this->first){
		// lasse first auf zweites Element der Liste (bzw. auf NULL) zeigen
		this->first = this->first->next;
		// loesche erstes Element (Medium) und den ersten Knoten
		delete tmpKnoten->item;
		delete tmpKnoten;
		// lasse Iterator auf erstes Element zeigen
		this->iterator = this->first;
	}
	// Iterator zeigt nicht auf erstes Element, es soll ein Knoten aus der Mitte der Liste / am Ende der Liste geloescht werden
	else {
		// suche Vorgaengerknoten (bis gefunden oder Ende der Liste erreicht)
		while((tmpKnoten != NULL) && (tmpKnoten->next != this->iterator)){
			tmpKnoten = tmpKnoten->next;
		}
		// gibt es ein Vorgaengerelement?
		if(tmpKnoten == NULL){
			return NULL;
		}
		tmpKnoten->next = this->iterator->next;
		// loesche Element (Medium) und Knoten
		delete this->iterator->item;
		delete this->iterator;
		// Iterator zeigt auf "
		this->iterator = tmpKnoten;
	}

	return true;
}


void Container::begin() {
	// setze Iterator auf erstes Element (bzw. auf NULL wenn keine Knoten in der Liste sind)
	this->iterator = this->first;
}


void Container::next() {
	// setze Iterator auf naechstes Element sofern Elemente in der Liste sind 
	// und der Iterator derzeit nicht auf das letzte Element der Liste zeigt
	if(this->iterator != NULL){
		this->iterator = this->iterator->next;
	}
}


T* Container::getitem() {
	// sind keine Elemente in der Liste gebe NULL zurueck
	if(this->iterator == NULL){
		return NULL;
	}
	// sonst gebe Zeiger auf aktuelles Element zurueck
	else {
		return this->iterator->item;
	}
}