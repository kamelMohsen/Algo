#include "QuickSort.h"

QuickSort::QuickSort(vector<int>* List) :Sorts(List)
{
}
void QuickSort::rec_quicksort(int left, int right)
{	
		if (left < right) 
		{
			int pivot = partition(left,right);
			rec_quicksort(left,pivot);
			rec_quicksort(pivot+1,right);
		}
}

int QuickSort::partition(int left,int right)
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


float QuickSort::getSortedList(int * SortedArray)
{
	auto start = chrono::steady_clock::now();
    rec_quicksort(0,ListSize-1);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	for (int i = 0; i < ListSize; i++)
	{
		SortedArray[i] = tempArray[i];
	}
	return (chrono::duration <double, milli>(diff).count());

}
