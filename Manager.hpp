#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

template<typename T>
class Manager {
	bool debug;
	unsigned int n;
	T** list;
public:
	Manager() {
		debug = false;
		n = 0;
		list = (T**)malloc(65536 * 4);
	}
	// Push | Pop pointers from the list
	T* push(T* ptr);
	bool pop(const T* ptr);

	//Functional
	T* getByIndex(int index) { return list[index]; }

	//Debug
	void setDebug(bool _debug) { this->debug = _debug; };
	void printList();
};

template<typename T>
bool Manager<T>::pop(const T *ptr)
{
	for (unsigned int i = 0; i < this->n; i++)
	{
		if (this->list[i] == ptr)
		{
			//Debug
			if (this->debug)printf_s("Deleting->List[%d]:", i);
			if (this->debug)printf_s(" %X...", (unsigned int)this->list[i]);

			//Stuff
			delete this->list[i];
			memmove(&this->list[i], &this->list[i + 1], (this->n - 1 - i) * 4);
			this->list[this->n - 1] = 0;
			this->n--;

			//Debug
			if (this->debug)printf_s("Done.\n");

			//Return
			return true;
		}
	}
	return false;
}

template<typename T>
T* Manager<T>::push(T * ptr)
{
	//Debug
	if (this->debug) printf_s("Adding [%X] to List[%d]..\n", (unsigned int)ptr, this->n);

	//Stuff
	list[n++] = ptr;

	//Debug
	if (this->debug) printf_s("[%X]List[%d]: %X\n", (unsigned int)&this->list[this->n - 1], this->n - 1, (unsigned int)this->list[this->n - 1]);

	//Return
	return ptr;
}

template<typename T>
void Manager<T>::printList()
{
	for (unsigned int i = 0; i < this->n; i++)
		printf_s("[%d/%d][%X]List[%d]: %X\n", i, (this->n - 1), (unsigned int)&this->list[i], i, (unsigned int)this->list[i]);
}
#endif // !MANAGER_HPP
