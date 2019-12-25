#include <algorithm>
#include <iostream>
using namespace std;


struct WT
{
	bool win;
	int turns;
};



WT predictWinner(int c1, int c2, int a1, int a2, int b1, int b2, WT** arr, WT** arr1, bool turn);

int main()
{

	int coins, a1, a2, b1, b2;
	cin >> coins >> a1 >> a2 >> b1 >> b2;
	bool turn = 0;

	WT** arr = new WT * [coins + 1];
	for (int i = 0; i < coins + 1; i++)
		arr[i] = new WT[coins + 1];

	WT** arr1 = new WT * [coins + 1];
	for (int i = 0; i < coins + 1; i++)
		arr1[i] = new WT[coins + 1];


	for (int i = 0; i < coins + 1; i++)
	{
		for (int j = 0; j < coins + 1; j++)
		{
			arr[i][j].turns = -1;
			arr[i][j].win = false;
			arr1[i][j].turns = -1;
			arr1[i][j].win = true;
		}
	}


	WT Ans = predictWinner(coins, coins, a1, a2, b1, b2, arr, arr1, turn);
	cout << Ans.win + 1 << " " << Ans.turns;
	return 0;
}



WT predictWinner(int c1, int c2, int a1, int a2, int b1, int b2, WT** arr, WT** arr1, bool turn)
{

	if (c1 <= 0 || c2 <= 0)
	{

		if (c1 <= 0 && c2 <= 0 && turn == 0)
		{
			WT RO;
			RO.turns = 0;
			RO.win = 0;
			return RO;
		}
		else if (c1 <= 0 && c2 <= 0 && turn  != 0)
		{
			WT RO;
			RO.turns = 0;
			RO.win = 1;
			return RO;
		}
		else if (c1 <= 0)
		{
			WT RO;
			RO.turns = 0;
			RO.win = 1;
			return RO;
		}
		else if (c2 <= 0)
		{
			WT RO;
			RO.turns = 0;
			RO.win = 0;
			return RO;
		}
	}


	WT a;


	if (turn  == 0)
	{

		if (arr[c1][c2].turns != -1)
		{
			a = arr[c1][c2];
			//return a;
		}
		else
		{

			a = predictWinner(c1 - a1, c2 - a2, a1, a2, b1, b2, arr, arr1,1);
			a.turns += 1;
		}
	}
	else if (turn   != 0)
	{
		if (arr1[c2][c1].turns != -1)
		{
			a = arr1[c2][c1];
			//return a;
		}
		else
		{
			a = predictWinner(c1 - a2, c2 - a1, a1, a2, b1, b2, arr, arr1, 0);
			a.turns += 1;
		}
	}
	WT b;

	if (turn   == 0)
	{
		if (c1 % 3  == 0)
		{
			if (arr[c1][c2].turns != -1)
			{
				b = arr[c1][c2];
				//return b;
			}
			else
			{
				b = predictWinner(c1, c2 - b1, a1, a2, b1, b2, arr, arr1, 1);
				b.turns += 1;
			}
		}
		else
		{
			if (arr[c1][c2].turns != -1)
			{
				b = arr[c1][c2];
				//return b;
			}
			else
			{
				b = predictWinner(c1 - b2, c2 - b2, a1, a2, b1, b2, arr, arr1, 1);
				b.turns += 1;
			}
		}

	}

	else if (turn   != 0)
	{
		if (c2 % 3 == 0)
		{
			if (arr1[c2][c1].turns != -1)
			{
				b = arr1[c2][c1];
			//	return b;
			}
			else
			{
				b = predictWinner(c1 - b1, c2, a1, a2, b1, b2, arr, arr1, 0);
				b.turns += 1;
			}
		}
		else
		{
			if (arr1[c2][c1].turns != -1)
			{
				b = arr1[c2][c1];
				//return b;
			}
			else
			{
				b = predictWinner(c1 - b2, c2 - b2, a1, a2, b1, b2, arr, arr1,0);
				b.turns += 1;
			}
		}

	}

	if (turn   == 0)
	{

		if (a.win == 0 && b.win == 0)
		{

			WT temp = ((a.turns > b.turns) ? a : b);
			//temp.turns++;
			arr[c1][c2] = temp;
			return temp;
		}
		else if (a.win == 0 && b.win == 1)
		{

			//a.turns++;
			arr[c1][c2] = a;
			return a;
		}
		else if (a.win == 1 && b.win == 0)
		{

			//b.turns++;
			arr[c1][c2] = b;
			return b;
		}
		else if (a.win == 1 && b.win == 1)
		{

			WT temp = ((a.turns < b.turns) ? a : b);
			//temp.turns++;
			arr[c1][c2] = temp;
			return temp;
		}
	}
	else if (turn   != 0)
	{

		if (a.win == 0 && b.win == 0)
		{

			WT temp = ((a.turns < b.turns) ? a : b);
			//temp.turns++;
			arr1[c2][c1] = temp;
			return temp;
		}
		else if (a.win == 0 && b.win == 1)
		{
			//b.turns++;
			arr1[c2][c1] = b;
			return b;
		}
		else if (a.win == 1 && b.win == 0)
		{
			//a.turns++;
			arr1[c2][c1] = a;
			return a;
		}
		else if (a.win == 1 && b.win == 1)
		{
			WT temp = ((a.turns > b.turns) ? a : b);
			//temp.turns++;
			arr1[c2][c1] = temp;
			return temp;
		}
	}
}