#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

char board[10][10];
mutex board_mutex;

class Plant {
private:
	int health;
public:
	Plant() {
		health = 100;
	}

	int getHealth() {
		return health;
	}

	void water() {
		health += 10;
		if (health > 100) health = 100;
	}

	void damage() {
		health -= 10;
		if (health < 0) health = 0;
	}
};

struct Position {
	int x, y;
};

class Gardener {
private:
	int id;
	Position position;
public:
	Gardener(int i) {
		id = i;
		position = { rand() % 10, rand() % 10 };
	}

	Position getPosition() {
		return position;
	}

	void move() {
		int dx = rand() % 3 - 1;
		int dy = rand() % 3 - 1;
		position.x += dx;
		position.y += dy;

		if (position.x < 0) position.x = 0;
		if (position.y < 0) position.y = 0;
		if (position.x >= 10) position.x = 9;
		if (position.y >= 10) position.y = 9;
	}

	void care() {
		int plant_health;
		char tchar;
		board_mutex.lock();
		plant_health = board[position.x][position.y];
		board_mutex.unlock();
		if (plant_health > 0) {
			if (rand() % 2 == 0) {
				plant_health += 10;
				tchar = 'M';
				if (plant_health > 100) {
					plant_health = 100;
					tchar = 'O';
				}
			}
			else {
				plant_health -= 10;
				tchar = 'm';
				if (plant_health < 0) {
					plant_health = 0;
					tchar = 'X';
				}
			}
			board_mutex.lock();
			board[position.x][position.y] = tchar;
			board_mutex.unlock();
		}
	}

	void operator()() {
		while (true) {
			move();
			care();
			board_mutex.lock();
			system("cls");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					cout << board[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			board_mutex.unlock();
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
};

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 'm';
		}
	}
	vector<Gardener> gardeners;
	for (int i = 0; i < 5; i++) {
		gardeners.emplace_back(i);
	}
	vector<thread> threads;
	for (auto& gardener : gardeners) {
		threads.emplace_back(gardener);
	}
	for (auto& t : threads) {
		t.join();
	}

	return 0;
}