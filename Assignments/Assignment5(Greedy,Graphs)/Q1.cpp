#include <list>
#include<iostream> 
using namespace std;
list<int> it;

void DFS(int n, int ind, int* arr, int& c, bool* visit, int** adjmat)
{
	if (visit[ind])
	{
		return;
	}
	visit[ind] = 1;
	//visited[i]=1;
	//int cu=0;
	int* subadjmat;
	/*	for(int i=0;i<n;i++)
{
	subadjmat[i]=adjmat[i];
}*/
/*	for(int j=0;j<n;j++)
{
	subadjmat[cu]=adjmat[i];
}*/

/*for(int i=0;i<n;i++)
{
	subadjmat[i]=adjmat[ind][i];
}*/

	subadjmat = adjmat[ind];
	c++;
	for (int i = 0; i < n; i++)
	{
		if (!visit[i] && subadjmat[i] == 1)
		{
			DFS(n, i, arr, c, visit, adjmat);
		}
	}
	it.push_back(ind);
}

int main()
{

	int n, x, y;
	cin >> n;
	int** adjmat = new int* [n];
	bool* visit = new bool[n];

	for (int i = 0; i < n; i++)
	{
		adjmat[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		visit[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x != -1)
		{
			adjmat[x][i] = 1;
		}
		if (y != -1)
		{
			adjmat[y][i] = 1;
		}
	}
	int* arr = new int[n];
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		DFS(n, i, arr, c, visit, adjmat);
	}
	for (int i = it.size() - 1; i >= 0; i--)
	{
		cout << it.back() << " ";
		it.pop_back();
	}

	//	system("pause");
}