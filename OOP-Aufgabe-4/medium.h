#pragma once

#include <string>

using namespace std;


enum Status {
	entliehen,
	vorhanden
};


class Medium {
	public:
		Medium();
		Medium(bool);
		~Medium();
		virtual void print();
		const void printHeadline();
		void ausleihen();
		void rueckgabe();
		int getSignatur();
	protected:
		int signatur;
		string titel;
		Status status;
};