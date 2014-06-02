#pragma once

#include <string>

using namespace std;

class StatusError {
	public:		
		StatusError(int signatur, int fehlercode);
		string messages();
	private:
		string fehlertext;
};