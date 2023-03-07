#pragma once
#include <mutex>
#include <condition_variable>

class MainWindow
{
public:
	MainWindow();
	void simulate();

private:
	int iTrucks, iGardens, iGardeners, iPlants, iTools, iClients, iFertilizer, iProducts;
	int iFreeTools;
	int iEmptyPlants, iPlantedPlants, iFertilizedPlants, iTrimmedPlants;
	int iMoney;
	std::mutex mtx;
	std::condition_variable cv_tools, cv_plants, cv_fertilizer, cv_products;

	void startGardenThread();
	void startGardenerThread();
	void startClientThread();
	void startTruckThread();
	void showInfo();
	void setData();
};