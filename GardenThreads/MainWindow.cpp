#include "MainWindow.h"
#include <thread>
#include <mutex>
#include <iostream>

MainWindow::MainWindow() {
	iClients = 3;
	iGardeners = 5;
	iTrucks = 2;
	iGardens = 1;
	iFertilizer = 3;
	iTools = 3;
	iProducts = 0;
	iPlants = 20;
}
