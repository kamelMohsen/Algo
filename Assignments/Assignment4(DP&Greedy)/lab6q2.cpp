#include <iostream>
using namespace std;

int minString(string s1, string s2);
int min(int a, int b);

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << minString(s1, s2);

	return 0;
}

int minString(string s1, string s2)
{
	int m = s1.size();
	int n = s2.size();
	m++;
	n++;
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
		arr[i] = new int[n];

	for (int i = 0; i < m; i++)
		arr[i][0] = i;
	for (int i = 0; i < n; i++)
		arr[0][i] = i;
	m--;
	n--;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1.at(i - 1) == s2.at(j - 1))
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = min(arr[i-1][j], arr[i][j-1]) + 1;
		}
	}

	return arr[m][n];
}

int min(int a, int b)
{
	return (a > b) ? b : a;
}
// this code was inspired by the • Longest Common Subsequence Algorithm presented in the slides(Page 20) 
// knowing that the algorithm was for longest I knew i had to switch to min to oppose and find the opposite algorithm