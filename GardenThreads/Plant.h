#pragma once
#include <string>

class Plant
{
public:
	char statusEmpty();
	char statusPlanted();
	char statusFertilized();
	char statusTrimmed();
	std::string getStatus();
private:
	char cPlantStatus;
};

