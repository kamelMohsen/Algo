#include "MergeSort.h"

MergeSort::MergeSort(vector<int>* List) :Sorts(List)
{
}

void  MergeSort::rec_mergesort(int left, int right)
{
	if (left < right)
	{
		int middle = left+(right-left)/2;
		rec_mergesort(left, middle);
		rec_mergesort(middle + 1, right);
		merge(left, middle, right);
	}
}

void MergeSort::merge(int left, int middle, int right)
{ 
    int LALength = middle-left+1; 
    int RALength =  right-middle; 
	int * leftArray = new int[LALength];
    int * rightArray = new int[RALength];

	for (int i = 0; i < LALength; i++)
	{
		leftArray[i] = tempArray[left + i];
	}
	for (int j = 0; j < RALength; j++)
	{
		rightArray[j] = tempArray[middle + 1 + j];
	}

	int LAIndex = 0;
	int RAIndex = 0;
	int startingIndex = left;
    while (LAIndex < LALength && RAIndex < RALength)
    { 
        if (leftArray[LAIndex] <= rightArray[RAIndex])
        { 
			tempArray[startingIndex] = leftArray[LAIndex];
			LAIndex++;
        } 
        else
        { 
			tempArray[startingIndex] = rightArray[RAIndex];
			RAIndex++;
        } 
        startingIndex++; 
    } 
    while (LAIndex < LALength)
    { 
		tempArray[startingIndex] = leftArray[LAIndex];
		LAIndex++;
        startingIndex++; 
    } 
    while (RAIndex < RALength)
    { 
		tempArray[startingIndex] = rightArray[RAIndex];
		RAIndex++;
        startingIndex++; 
    } 
}

float MergeSort::getSortedList(int * SortedArray)
{
	auto start = chrono::steady_clock::now();
	rec_mergesort(0,ListSize-1);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	for (int i = 0; i < ListSize; i++)
	{
		SortedArray[i] = tempArray[i];
	}
	return (chrono::duration <double, milli>(diff).count());
}
