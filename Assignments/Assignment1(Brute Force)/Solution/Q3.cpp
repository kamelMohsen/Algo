#include <iostream>
#include <sstream> 
using namespace std;


int findmin(int arr[], int i, int j)
{
	if (i == j)
		return 0;
	
	int min = INT16_MAX;
	int count;


	for (int  k = i; k < j; k++)
	{
		count = findmin(arr, i, k) +
			findmin(arr, k + 1, j) +
			arr[i - 1] * arr[k] * arr[j];

		if (count < min)
			min = count;
	}


	return min;

}
int main()
{
	string O = "";
	getline(cin,O);
	stringstream s(O);
	string word;
	int count = 0;
	while (s >> word)
	{
		count++;
	}
	stringstream x(O);
	int* Inputs = new int[count];
	for (int i = 0; i < count; i++)
	{
		x >> Inputs[i];
	}
	int* data = new int[count];
	int min = findmin(Inputs,1,count-1);
	cout << min;
	return 0;
}