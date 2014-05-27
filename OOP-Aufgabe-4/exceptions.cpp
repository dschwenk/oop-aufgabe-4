#include "exceptions.h"

using namespace std;


StatusError::StatusError(int signatur, int fehlercode) {
	ostringstream s;
	// Stream zur Logdatei ERROR.LOG oeffnen (Datei anlegen sofern diese nicht besteht) und Fehlertext anhaengen
	fstream log("ERROR.LOG", ios::out | ios::app);

	// fehlernr = 1 - Fehler bei Rueckgabe
	// fehlernr = 0 - Fehler bei Ausleihe
	if(fehlercode){
		s << "\nFehler bei der Ruecknahme von Signatur: ";
	}
	else { 
		s << "\nFehler beim Verleih von Signatur: ";
	}
	s << signatur << "\n";

	// in Logdatei schreiben und Datei schliessen
	fehlertext = s.str();
	log << fehlertext;
	log.close();
}


string StatusError::text(){
	return this->fehlertext;
}