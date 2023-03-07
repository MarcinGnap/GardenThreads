#include "MainWindow.h"
#include <thread>
#include <iostream>

using namespace std;

MainWindow::MainWindow() {
	iClients = 3;
	iGardeners = 5;
	iTrucks = 2;
	iGardens = 1;
	iFertilizer = 3;
	iTools = 3;
	iProducts = 10;
	iPlants = 20;
	iMoney = 0;
	iFreeTools = iTools;
}

void MainWindow::simulate() {

}

void MainWindow::startGardenThread(){

}

void MainWindow::startGardenerThread() {

}

void MainWindow::startClientThread() {

}

void MainWindow::startTruckThread() {

}

void MainWindow::showInfo() {
	// change in case of addin some graphic or sth

	mtx.lock();

	for (int g = 0; g < iGardens; g++) {
		cout << "Garden: " << g + 1 << endl << endl;
		cout << "Gardeners: " << iGardeners << endl;
		cout << "Trucks: " << iTrucks << endl;
		cout << "Clients: " << iClients << endl;
		cout << "Plants: " << iPlants << endl;
		cout << "\tEmpty spot: " << iEmptyPlants << "\n \tFreshly planted: " << iPlantedPlants << "\n \tFertilized plant: " << iFertilizedPlants << "\n \tTrimmed plant: " << iTrimmedPlants << endl;
		cout << "Tools: " << iTools<< endl;
		cout << "\tFree: " << iFreeTools << "\n \tOccupied: " << iTools - iFreeTools << endl;
		cout << "Bags of fertilizer: " << iFertilizer << endl;
		cout << "Available products: " << iProducts << endl << endl;
		cout << "Money earned: " << iMoney << endl << endl;
	}

	// waitin for btn or has to refresh automatically
	mtx.unlock();
}