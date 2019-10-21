#include <fstream>
#include <vector> 
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HybridSort.h"
#include <chrono>
#include <iostream>
using namespace std;

void WriteToFile(string a, string b, float Time, int ListSize, int* SortedArray);


int main(int argc, char *argv[])
{
	ifstream inFile;
	inFile.open(argv[2]);
	if (!inFile)
	{
		cerr << "Unable to open file datafile.txt";
		exit(1);   
	}
	
	int x = 0;
	vector<int> List;
	while (inFile >> x)
	{
		List.push_back(x);
	}

	int sortMethod = atoi(argv[1]) ;

	int* SortedArray = new int[List.size()];
	float Time = 0;

	if (sortMethod == 0)
	{
		SelectionSort a(&List);
		Time = a.getSortedList(SortedArray);
		WriteToFile(argv[3], argv[4], Time, List.size(), SortedArray);
	}
	else if (sortMethod == 1)
	{
		InsertionSort a(&List);
		Time = a.getSortedList(SortedArray);
		WriteToFile(argv[3], argv[4], Time, List.size(), SortedArray);
	}
	else if (sortMethod == 2)
	{
		MergeSort a(&List);
		Time = a.getSortedList(SortedArray);
		WriteToFile(argv[3], argv[4], Time, List.size(), SortedArray);
	}
	else if (sortMethod == 3)
	{
		QuickSort a(&List);
		Time = a.getSortedList(SortedArray);
		WriteToFile(argv[3], argv[4], Time, List.size(), SortedArray);
	}
	else if (sortMethod == 4)
	{
		HybridSort a(&List);
		Time = a.getSortedList(SortedArray);
		WriteToFile(argv[3], argv[4], Time, List.size(), SortedArray);
	}
	inFile.close();
	return 0;
}























void WriteToFile(string a, string b, float Time,int ListSize,int * SortedArray)
{
	ofstream SelectionFile, TimingFile;

	SelectionFile.open(a);
	for (int i = 0; i < ListSize; i++)
	{
		SelectionFile << SortedArray[i] << "\n";
	}

	TimingFile.open(b);
	TimingFile << Time << " ms" << endl;
	TimingFile.close();
	SelectionFile.close();
}
