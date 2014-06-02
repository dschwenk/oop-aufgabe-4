#include <fstream>
#include <sstream>
#include "exceptions.h"

using namespace std;


StatusError::StatusError(int signatur, int fehlercode) {
	
	ostringstream s;	
	// Fehlercode 0 - Entleihen
	// Fehlercode 1 - Rueckgabe
	if(fehlercode == 0){
		s << "Fehler beim Leihen von Signatur ";
	}
	else {
		s << "Fehler beim Rueckgeben von Signatur ";
		}
	s << signatur << ".\n" ;
	// in String konvertieren
	fehlertext = s.str();
	
	// Stream zur Logdatei ERROR.LOG oeffnen und Fehlertext anhaengen (Datei wird angelegt sofern diese nicht besteht) 
	// Verknpuepfung der Modi durch |
	ofstream errorlog("ERROR.LOG", ios::out | ios::app);

	// in Logdatei schreiben und Datei schliessen
	errorlog << fehlertext;
	errorlog.close();
}


string StatusError::messages(){
	return this->fehlertext;
}