#ifndef MANAGER_H
#define MANAGER_H
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

class Player {
public:
	Player() { printf_s("Player Allocated %X\n", (unsigned int)this); }
	~Player() { printf_s("Player Deleted %X\n", (unsigned int)this); }
};

class Manager {
	bool debug;
	unsigned int n;
	Player** list;
public:
	Manager() {
		debug = false;
		n = 0;
		list = (Player**)malloc(65536 * 4);
	}
	// Push | Pop pointers from the list
	Player* push(Player* ptr);
	bool pop(Player* ptr);

	//Functional
	Player* getByIndex(int index) { return list[index]; }

	//Debug
	void setDebug(bool _debug) { this->debug = _debug; };
	void printList();
};
#endif // !STDAFX_H
