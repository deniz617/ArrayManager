#include "Manager.h"

bool Manager::pop(Player * ptr)
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

Player* Manager::push(Player * ptr)
{
	//Debug
	if (this->debug) printf_s("Adding [%X] to List[%d]..\n", (unsigned int)ptr, this->n);

	//Stuff
	list[n++] = ptr;

	//Debug
	if (this->debug) printf_s("[%X]List[%d]: %X\n", (unsigned int)&this->list[this->n-1], this->n - 1, (unsigned int)this->list[this->n - 1]);

	//Return
	return ptr;
}

void Manager::printList()
{
	for (unsigned int i = 0; i < this->n; i++)
		printf_s("[%d/%d][%X]List[%d]: %X\n", i, (this->n - 1), (unsigned int)&this->list[i], i, (unsigned int)this->list[i]);
}
