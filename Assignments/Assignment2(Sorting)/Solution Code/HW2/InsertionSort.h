#pragma once
#include "Sorts.h"
#include <chrono>
class InsertionSort :
	public Sorts
{
public:
	InsertionSort(vector<int> * List);
	float getSortedList(int * SortedArray);
};

