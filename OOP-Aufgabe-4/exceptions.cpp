#include <iostream>
#include <fstream>
#include <sstream>
#include "exceptions.h"

using namespace std;


StatusError::StatusError(int signatur) {
	ostringstream s;	
	s << "Fehler beim Leihen/Rueckgeben von Signatur ";
	s << signatur << "\n" ;
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