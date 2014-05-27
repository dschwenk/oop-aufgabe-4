#pragma once

#include "medium.h"

using namespace std;

// T ist der Typ der Containerelemente
typedef Medium T;


// Knotenklasse - Knoten beinhaltet Zeiger auf den nachfolgenden Knoten und auf ein Element (Medium)
class Knoten {
	public:
		Knoten(Knoten* next, T* item);
	protected:
		friend class Container;
		// Zeiger auf den naechsten Knoten
		Knoten* next;
		// Zeiger auf das Element (Medium)
		T* item;
};


// Containerklasse - ermoeglicht verwaltung der Elemente in einer verketteten Liste
class Container {
	public:
		Container();
		// Element zur Liste / zum Container hinzufuegen
		void add(T* element);
		// Element aus Liste / aus Container entfernen
		bool remove();
		// Iterator auf erstes Element der Liste setzen		
		void begin();
		// Iterator auf aktuelles Element setzen		
		void next();
		// aktuelles Element zurueck geben
		T* getitem();
	protected:
		// Zeiger auf das erste Containerelement
		Knoten* first;
		// Zeiger auf das aktuelle Containerelement
		Knoten* iterator;
};