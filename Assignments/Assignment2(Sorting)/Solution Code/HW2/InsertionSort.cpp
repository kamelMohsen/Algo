#include "InsertionSort.h"

InsertionSort::InsertionSort(vector<int> * List) :Sorts(List)
{
}


float InsertionSort::getSortedList(int * SortedArray)
{
	auto start = chrono::steady_clock::now();
	for (int j = 1; j< ListSize; j++) {
		int temp = tempArray[j];
		int k = j;
		while (k > 0 && tempArray[k-1] > temp) {
			tempArray[k] = tempArray[k-1];
			k--;
		}
		tempArray[k] = temp;
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	for (int i = 0; i < ListSize; i++)
	{
		SortedArray[i] = tempArray[i];
	}
	return (chrono::duration <double, milli>(diff).count());
}
