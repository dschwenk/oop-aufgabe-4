#pragma once

#include <string>

using namespace std;


enum Status {
	entliehen,
	praesent
};


class Medium {
	public:
		Medium(bool);
		~Medium();
		virtual void print();
		static void printHeadline();
		void ausleihen();
		void rueckgabe();
		int getSignatur();
	protected:
		int signatur;
		string titel;
		Status status;
};