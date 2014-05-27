#pragma once

#include "medium.h"

class Buch: public Medium {
	public:
		Buch();
		void print();
	private:
		int seitenzahl;
};