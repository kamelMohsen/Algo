#include "Sorts.h"

Sorts::Sorts(vector<int>* List)
{
	ListSize = List->size();
	tempArray = new int[ListSize];
	for (int i = 0; i < ListSize; i++)
	{
		tempArray[i] = List->at(i);
	}


}



Sorts::~Sorts()
{
	delete[] tempArray;
}
