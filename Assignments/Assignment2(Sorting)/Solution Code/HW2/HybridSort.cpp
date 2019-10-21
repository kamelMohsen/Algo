#include "HybridSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
HybridSort::HybridSort(vector<int>* List) :Sorts(List)
{
	HList = *List;
	counter = 0;
	
}

void HybridSort::rec_hybridsort(int left, int right)
{
	if (left < right)
	{	

			int pivot = partition(left, right);
			rec_hybridsort(left, pivot);
			rec_hybridsort(pivot + 1, right);

	}
}		
	


int HybridSort::partition(int left, int right)
{

	int temp = tempArray[left];


	int i = left - 1;
	int j = right + 1;

	while (true)
	{
		j--;
		if (tempArray[j] <= temp)
		{
			do
			{
				i++;
			} while (tempArray[i] < temp);

			if (i < j)
			{
				int swapTemp = tempArray[i];
				tempArray[i] = tempArray[j];
				tempArray[j] = swapTemp;
				continue;
			}
			break;
		}
	}

	return j;
}

int HybridSort::insertionsort(int left, int right)
{
	int k = 0;
	for (int j = left+1; j < right; j++) 
	{
		int temp = tempArray[j];
	    k = j;
		if (tempArray[k - 1] > temp)
			counter++;
		while (k > 0 && tempArray[k - 1] > temp) 
		{
			tempArray[k] = tempArray[k - 1];
			k--;
		}

		tempArray[k] = temp;
		if (counter > 10000)
			break;
	}
	return k;

}

float HybridSort::getSortedList(int* SortedArray)
{
	auto start = chrono::steady_clock::now();
	rec_hybridsort(insertionsort(0, ListSize - 1), ListSize - 1);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	for (int i = 0; i < ListSize; i++)
	{
		SortedArray[i] = tempArray[i];
	}
	return (chrono::duration <double, milli>(diff).count());
}
