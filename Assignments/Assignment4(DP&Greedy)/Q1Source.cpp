#include <vector>
#include <iostream>
using namespace std;



int* minShots(int Shots[], int Health[], int N,int M);
void  getSortedList(int* SortedArray, int size);
int main()
{

	int N, M;
	cin >> N;
	int* Healthes = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> Healthes[i];
	}
	cin >> M;

	int* Shots = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> Shots[i];
	}

	int* savedValues;
	savedValues = minShots(Shots, Healthes, N ,M);
	for (int i = 0; i < N; i++)
	{
		cout << (int)savedValues[i] << endl;
	}
	return 0;
}

int* minShots(int Shots[], int Health[], int N,int M)
{
	int* savedValues = new int[N];
	for (int i = 0; i < N; i++)
		savedValues[i] = 0;
	getSortedList(Shots, M);
	for (int i = 0; i < N; i++)
	{
		for (int j = (M-1); j>= 0; j--)
		{
			while (Shots[j] <= Health[i])
			{
				Health[i] -= Shots[j];
				savedValues[i] ++;
				
			}
		}
		
	}

	return savedValues;
}



void  getSortedList(int* SortedArray,int size)
{

	for (int j = 1; j < size; j++) {
		int temp = SortedArray[j];
		int k = j;
		while (k > 0 && SortedArray[k - 1] > temp) {
			SortedArray[k] = SortedArray[k - 1];
			k--;
		}
		SortedArray[k] = temp;
	}
	

}
