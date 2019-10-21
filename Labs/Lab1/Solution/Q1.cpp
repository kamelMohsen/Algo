#include <iostream>
using namespace std;

// this is my solution for question 1 lab1 i used adjacency matrix to solve the question i am not sure of the solution but her it is



int main()
{
	int  vertices = 0,edges = 0;
    //intializing the first two inputs
	cin >> vertices;
	cin >> edges;
	//taking the first two inputs
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
	
		scanf_s("%i %i", &v1, &v2);
		adj[v1][v2] = 1;
		adj[v2][v1] = 1;

	}
	//taking all the edges
	int tempsize = 0;
	
	tempsize = vertices + 1;
	
	int* arrcs = new int[tempsize];
	
	int sizeofarrcs = 0 ;
	
	int fmaxcover = 0 , imaxcover = 0 ;
	for (int i = 0; i < vertices; i++)
	{
		imaxcover = 0;

		for (int j = 0; j < vertices; j++)
		{

			if (adj[i][j] == 1)
			{
				imaxcover++;
			}

		}
		if (imaxcover > fmaxcover)
		{
			fmaxcover = imaxcover;
			sizeofarrcs = 0;
			arrcs[sizeofarrcs] = i;
		}
		if (imaxcover == fmaxcover)
		{
			sizeofarrcs++;
			arrcs[sizeofarrcs] = i;
		}
	}
	if (sizeofarrcs == edges)
	{
		sizeofarrcs--;
	}
	cout << sizeofarrcs <<endl;
	for (int i = 1; i <= sizeofarrcs; i++)
	{
		cout<<arrcs[i]<<" ";
	}
	//this algorithim is based on the concept of checking each vertex to check if it is a vertex cover for all the rest

	return 0;
}