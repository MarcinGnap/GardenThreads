#include "MainWindow.h"
#include <thread>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	//	MainWindow window;

	auto hello = [](int x) {
		cout << "Hello there \nGeneral Kenobi... \nThis is thread: " << this_thread::get_id() << endl;
		cout << "Kept in: " << x << endl;
	};


	vector<thread> firstThreads;
	
	for (int i = 0; i < 10; i++) {
		firstThreads.push_back(thread(hello, i));
		firstThreads[i].join();
	}


	cout << "Hello there \nGeneral Kenobi... \nThis is main thread" << endl;

	return 0;
}