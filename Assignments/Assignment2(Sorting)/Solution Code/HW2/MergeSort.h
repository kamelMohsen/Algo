#pragma once
#include "Sorts.h"
#include <chrono>
class MergeSort :
	public Sorts
{
public:
	MergeSort(vector<int>* List);
	void rec_mergesort(int left, int right);
	void merge(int left, int middle, int right);
	float getSortedList(int * SortedArray);
};

