#include <iostream>
using namespace std;

int minPath(int ** arr, int N , int M);
int minimum(int a, int b, int c);
int main()
{
	int N = 0, M = 0;
	cin >> N>>M;
	int ** arr = new int*[N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[M];


	for (int i = 0; i < N; i++)
	{
		for(int j = 0 ; j < M ; j++)
			cin >> arr[i][j];
	}

	cout << minPath(arr, N, M);
	return 0;
}

int minPath(int** arr, int N, int M)
{
	int ** mins = new int * [N];
	for (int i = 0; i < N; i++)
		mins[i] = new int[M];

	for (int i = N-1; i >= 0; i--)
	{
		for (int j = M-1; j >= 0; j--)
		{
			mins[i][j] = 0;
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = M - 1; j >= 0; j--)
		{

			if (i == N-1 && j == M-1)
				mins[i][j] = arr[i][j];
			else if(i<N-1 && j<M-1)
				mins[i][j] = minimum(mins[i+1][j+1], mins[i+1][j], mins[i][j+1])+arr[i][j];
			else if (i==N-1 && j != M-1)
				mins[i][j] = mins[i][j + 1] + arr[i][j];
			else if (i != N - 1 && j == M - 1)
				mins[i][j] = mins[i+1][j] + arr[i][j];

		}
	}
	return mins[0][0];
}

int minimum(int a, int b, int c)
{
	int min = 99999;
	if (a < min)
		min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;

	return min;
}
