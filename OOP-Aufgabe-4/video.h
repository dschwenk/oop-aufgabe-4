#pragma once

#include "medium.h"

class Video: public Medium {
	public:
		Video();
		void print();
	private:
		float spieldauer;
};