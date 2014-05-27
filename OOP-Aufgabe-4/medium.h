#pragma once

#include <string>

using namespace std;

class Medium {
	public:
		Medium();
		Medium(bool);
		~Medium();
		void print();
		void ausleihen();
		void rueckgabe();
		int getSignatur();
		bool getAvailable();
	protected:
		int signatur;
		string titel;
		bool entliehen;
};