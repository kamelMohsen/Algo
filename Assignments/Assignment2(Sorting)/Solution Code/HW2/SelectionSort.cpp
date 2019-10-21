#include "SelectionSort.h"

SelectionSort::SelectionSort(vector<int>* List):Sorts(List)
{
}

float SelectionSort::getSortedList(int * SortedArray)
{
	auto start = chrono::steady_clock::now();
	for (int j = ListSize-1; j > 0; j--) 
	{
		int max = 0;
		for (int k = 1; k <= j; k++) {
			if (tempArray[k] > tempArray[max])
			{
				max = k;
			}
		}
		if (j != max) {
			int temp = tempArray[j];
			tempArray[j] = tempArray[max];
			tempArray[max] = temp;
		}
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	for (int i = 0; i < ListSize; i++)
	{
		SortedArray[i] = tempArray[i];
	}
	return (chrono::duration <double, milli>(diff).count());
}