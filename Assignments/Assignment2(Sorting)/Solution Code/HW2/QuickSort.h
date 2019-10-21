#pragma once
#include "Sorts.h"
#include <chrono>
class QuickSort :
	public Sorts
{
public:
	QuickSort(vector<int>* List);
	void rec_quicksort(int left, int right);
	int partition(int left,int right);
	float getSortedList(int * SortedArray);
};

