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
		cout << "Garden: " << g + 1 << endl;
		cout << "Number of gardeners: " << iGardeners << endl;
		cout << "Number of trucks: " << iTrucks << endl;
		cout << "Number of clients: " << iClients << endl;
		cout << "Number of plants: " << iPlants << endl;
		cout << "Number of tools: " << iTools<< endl;
		cout << "Number of bags of fertilizer: " << iFertilizer << endl;
		cout << "Number of available products: " << iProducts << endl;
	}

	// waitin for btn
	mtx.unlock();
}