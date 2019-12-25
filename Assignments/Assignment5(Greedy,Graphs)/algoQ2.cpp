#include <vector> 
#include <iostream>
using namespace std;

struct malhashlazma
{
	int baba;
	int mama;

};

void DFS(int start, bool* visited);


int n;
bool** adjmat;
vector <int> myVec;


int main()
{


	cin >> n;
	bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	
	adjmat = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		adjmat[i] = new bool[n];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			adjmat[i][j] = 0;
		}
	}


	malhashlazma ellyda5el ;

	for (int i = 0; i < n; i++)
	{
		cin >> ellyda5el.baba >> ellyda5el.mama;


		if(ellyda5el.baba!=-1)
		adjmat[ellyda5el.baba][i] = true;

		if (ellyda5el.mama != -1)
		adjmat[ellyda5el.mama][i] = true;
	}

	for (int i = 0; i < n; i++)
	{
		DFS(i,visited);
	}


	for(int i = myVec.size()-1; i>=0;i--)
	{
		cout << myVec.at(i) << " ";
	
	}

	return 0;
}

void DFS(int start, bool* visited)
{

	if (visited[start] == true)
	{
		return;
	}

	visited[start] = true;


	for (int i = 0; i < n; i++)
	{


		if (adjmat[start][i]== true  && (visited[i] == 0))
		{
			DFS(i, visited);
		}
	}
	
	myVec.push_back(start);

}