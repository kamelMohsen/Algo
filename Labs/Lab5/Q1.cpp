#include <vector>
#include <iostream>
using namespace std;



int minCoins(int coins[],int V,int N);

int main()
{

	int V, N;
	cin >> V >> N;
	int * coins = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}
	cout << minCoins(coins, V, N);
	return 0;
}

int minCoins(int coins[], int V, int N)
{
	int * savedValues = new int[V+1];
	savedValues[0] = 0;
	for (int i = 1; i <= V  ; i++)
		savedValues[i] = 999999;

	for (int i = 1; i <= V  ; i++)
	{ 
		for (int j = 0; j < N; j++)
			if (coins[j] <= i)
			{
				int temp = savedValues[i - coins[j]] + 1;
				if (temp  < savedValues[i] )
					savedValues[i] = temp ;
			}
	}
	return savedValues[V];
}
