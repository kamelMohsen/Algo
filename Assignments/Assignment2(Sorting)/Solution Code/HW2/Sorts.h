#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Sorts
{
public:
	vector<int>* List;
	int* tempArray;
	int ListSize;
	Sorts(vector<int>* List);
	~Sorts();
};

