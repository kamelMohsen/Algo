#include <iostream>
using namespace std;

int max(int a, int b);
int cutRibbon(int cuts[], int length);

int main()
{

	int length = 0, a = 0, b = 0, c = 0;
	cin >> length >> a >> b >> c;
	int cuts[] = { a,b,c };
	
	cout << cutRibbon(cuts, length);

	return 0;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int cutRibbon(int cuts[], int length)
{
	int * val = new int[length + 1];
	int x, y, z;
	val[0] = 0;
	for (int i = 1; i <= length; i++)
	{
		x = (i >= cuts[0]) ? val[i - cuts[0]] : -999999;
		y = (i >= cuts[1]) ? val[i - cuts[1]] : -999999;
		z = (i >= cuts[2]) ? val[i - cuts[2]] : -999999;
		val[i] = max(max(x, y), z) + 1;
	}
	return val[length];
}
