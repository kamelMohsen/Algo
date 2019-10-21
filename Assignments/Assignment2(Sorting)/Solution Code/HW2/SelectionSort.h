#pragma once
#include "Sorts.h"
#include <chrono>
class SelectionSort :
	public Sorts
{
public:
	SelectionSort(vector<int>* List);
	float getSortedList(int * SortedArray);
};

