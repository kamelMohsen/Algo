#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm> 
using namespace std;
int check(int data[],int r, int** adj)
{
	int sum = 0;
	bool isConnected = true;
	for (int i = 0; i < r  ; i++)
	{
	
		int j = i+1;
		int i1 = data[i];
		int i2 = data[j];
		if (j == r && adj[data[0]][i1] > 0)
		{
			sum += adj[data[0]][i1];
			return sum;
		}
		else if( j == r )
			return INT16_MAX;
		if (adj[i1][i2] > 0)
		{
			sum += adj[i1][i2];
		}
		else
		{
			isConnected = false;
			break;
		}
	}
	if (isConnected)
	{
		return sum;
	}
	return INT16_MAX;
}


void findMin(int arr[],int r,int &min,int ** adj,int source)
{
	int lmin = INT16_MAX;

	sort(arr, arr + r);
	do {
		if (arr[0] == source)
		{
			lmin = check(arr, r, adj);
			if (lmin < min && lmin != 0)
			{
				min = lmin;
			}
		}
	
	} while (next_permutation(arr, arr + r));
	

	
}

int main() {

	int  vertices = 0, edges = 0, source = 0;
	int min = INT16_MAX;
	//intializing the first two inputs
	cin >> vertices>>source;
	if (vertices == 0)
	{
		min = -1;
		cout << min;
		return 0;

	}
	cin >> edges;


	//taking the first two inputs
	if (edges == 0)
	{
		min = -1;
	}
	if (vertices != 1 && edges != 0)
	{
		int v1 = 0, v2 = 0, dist = 0;
		//intializing variables for taking edges from user
		int** adj = new int* [vertices];
		for (int i = 0; i < vertices; i++)
		{
			adj[i] = new int[vertices];
		}
		//craeting adjacency matrix
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				adj[i][j] = 0;
			}
		}

		//filling the matrix with zereos
		
		for (int i = 0; i < edges; i++)
		{

			scanf("%i %i %i", &v1, &v2, &dist);
			adj[v1][v2] = dist;
			adj[v2][v1] = dist;

		}

		if (vertices == 2 && edges == 1)
		{
			min = dist;
			cout << dist;
			return 0;
		}
		
		int* arr = new int[vertices];
		for (int i = 0; i < vertices; i++)
		{
			arr[i] = i;

		}
			findMin(arr, vertices, min, adj, source);
	
		
		if (min == INT16_MAX)
		{
			cout << -1;
			return 0;
		}
	
	
	}
	if (min == INT16_MAX)
	{
		cout << -1;
		return 0;
	}
	cout << min;
	return 0;


}
