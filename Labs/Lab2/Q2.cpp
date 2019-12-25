#include <iostream>
using namespace std;


int findSum(int A[], int N)
{
	if (N <= 0)
		return 0;
	return (findSum(A, N - 1) + A[N - 1]);
}

void combinationUtil(int arr[], int data[],
	int start, int end,
	int index, int r , int sum,bool &found,int arrofc[],int &lenofs)
{
	
	if (index == r)
	{
		
		if (findSum(data, r) == sum)
		{
			found = true;
			lenofs = r;
			for (int i = 0; i < r; i++)
			{
				arrofc[i] = data[i];
			}
			
		}
		return ;
	}

  
	for (int i = start; i <= end &&
		end - i + 1 >= r - index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i + 1,
			end, index + 1, r, sum, found, arrofc,lenofs);

	}
}



int main()
{





	int lenofs = 0;
	int r = 0;
	int sum = 0;
	int len = 0;
	bool found = false;
	cout << "Enter the number of the elements: ";
	cin >> len;
	int *arr = new int[len];
	cout << "Enter first Element: ";
	for (int i = 0; i < len; i++)
	{
		if (i > 0)
			cout << "Enter next Element: ";
		cin>>arr[i];
		
	}
	cout << "Enter the sum: ";
	cin >> sum;
	int* data = new int[len];
	int* arrofc = new int[len];

	for (int i = 1; i <= len; i++)
	{
	
    r = i;
	combinationUtil(arr,data,0,len-1,0,r,sum,found,arrofc,lenofs);    
	}
	cout << found<<endl;

	for (int i = 0; i < lenofs; i++)
	{

		cout << arrofc[i] << "  ";

	}
	return 0;
}