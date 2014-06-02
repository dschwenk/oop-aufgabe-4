#pragma once

#include <string>

using namespace std;

class StatusError {
	public:		
		StatusError(int signatur);
		string messages();
	private:
		string fehlertext;
};