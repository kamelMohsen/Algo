#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



int main()
{
	int N = 0;
	cin >> N;
	
	vector<long long> row1;
	vector<long long> row2;
	long long a;
	for (int i = 0; i < N; i++)
	{

		cin >> a;
			row1.push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> a;
			row2.push_back(a);
	}


	long long  savedValues[2] ;
	savedValues[0] = row1[0];
	savedValues[1] = row2[0];
	long long temp1 = 0;
	long long temp2 = 0;

	for (int i = 1; i < N; i++)
	{
		temp1 = max(savedValues[1] + row1[i], savedValues[0]);
		temp2 = max(savedValues[0] + row2[i], savedValues[1]);
		savedValues[0] = temp1;
		savedValues[1] = temp2;
	}

	long long ans = max(savedValues[0] , savedValues[1]);
	cout << ans;



	return 0;
}



