#include "Tool.h"

Tool::Tool()
{
	statusFree();
}

std::string Tool::getStatus()
{
	if (cToolStatus == 'f') {
		return "Free";
	}
	else if (cToolStatus == 'o') {
		return "Occupied";
	}
	else {
		return "Error";
	}
}

void Tool::statusOccupied()
{
	cToolStatus = 'o';
}

void Tool::statusFree()
{
	cToolStatus = 'f';
}
