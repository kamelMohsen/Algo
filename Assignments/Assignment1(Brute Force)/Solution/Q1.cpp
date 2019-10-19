#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <chrono>
using namespace std;

void findmcl(int& mClS, int v, int* arr, int** adj, int* testArr)
{
	int c = 0;
	for (int i = 0; i < v; i++)
	{
		if (arr[i] == 1)
		{
			testArr[c] = i;
			c++;
		}
	}
	bool isClique = true;
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (adj[testArr[i]][testArr[j]] != 1 && i!=j)
				isClique = false;
		}
	}

	if (c > mClS && isClique)
	{
		mClS = c;
	}
}


void findMax(int& mClS, int Vertices, int* arr, int** adj, int x, int* testArr)
{
	findmcl(mClS, Vertices, arr, adj, testArr);
	if (x == Vertices)
		return;

	arr[x] = 0;
	findMax(mClS, Vertices, arr, adj, x + 1, testArr);
	arr[x] = 1;
	findMax(mClS, Vertices, arr, adj, x + 1, testArr);
}

int main() {
	//auto start = chrono::steady_clock::now();
	
	int  vertices = 0, edges = 0;
	int max = 0;
	//intializing the first two inputs
	cin >> vertices;
	if (vertices == 0)
	{
		max = -1;
		cout << max;
		return 0;
	}
	cin >> edges;
	if (vertices == 2 && edges == 1)
	{
		max = 2;
		cout << max;
		return 0;
	}
         //taking the first two inputs
	if (edges == 0)
	{
		max = 1;
	}
	if (vertices != 1 && edges != 0)
	{
		int v1 = 0, v2 = 0;
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
			scanf("%i %i", &v1, &v2);
			adj[v1][v2] = 1;
			adj[v2][v1] = 1;
		}
		//taking all the edges
		int* arr = new int[vertices];
		for (int i = 0; i < vertices; i++)
		{
			arr[i] = 0;
		}
		int x = 0;
		int* testArr = new int[vertices];
		findMax(max, vertices, arr, adj, x, testArr);
	}
	cout << max;
	//auto end = chrono::steady_clock::now();
	//auto diff = end - start;
	//cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	return 0;
}