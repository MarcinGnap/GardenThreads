#include "Plant.h"

Plant::Plant()
{
	statusEmpty();
}

char Plant::statusEmpty()
{
	cPlantStatus = 'e';
	return cPlantStatus;
}

char Plant::statusPlanted()
{
	cPlantStatus = 'p';
	return cPlantStatus;
}

char Plant::statusFertilized()
{
	cPlantStatus = 'f';
	return cPlantStatus;
}

char Plant::statusTrimmed()
{
	cPlantStatus = 't';
	return cPlantStatus;
}

std::string Plant::getStatus()
{
	if(cPlantStatus == 'e'){
		return "Free spot";
	}
	else if(cPlantStatus == 'p') {
		return "Planted";
	}
	else if (cPlantStatus == 'f') {
		return "Fertilized";
	}
	else if (cPlantStatus == 't') {
		return "Trimmed";
	}
	else{
		return "Error";
	}
}
