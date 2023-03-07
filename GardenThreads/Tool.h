#pragma once
#include <string>

class Tool
{
public:
	Tool();
	std::string getStatus();
	void statusOccupied();
	void statusFree();
private:
	char cToolStatus;
};

