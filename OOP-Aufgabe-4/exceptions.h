#pragma once

#include <string>
#include <iostream>

using namespace std;

class StatusError {
	public:		
		StatusError(int signatur, int fehlercode);
		string text();
	private:
		string fehlertext;
};