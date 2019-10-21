#pragma once
#include "Sorts.h"
#include <chrono>
class HybridSort :
	public Sorts
{
	
public:
	int counter, lastPivot,sortedTill;
	string ender;
	vector<int> HList;
	HybridSort(vector<int>* List);
	void rec_hybridsort(int left, int right);
	int partition(int left, int right);
	int insertionsort(int left,int right);
	float getSortedList(int* SortedArray);
};

