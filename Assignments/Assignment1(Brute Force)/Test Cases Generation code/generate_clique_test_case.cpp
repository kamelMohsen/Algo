#include <iostream>
using namespace std;

int main(){
	int N ;
	for (N = 2; N < 31; N++)
	{
		cout << "------------------------------------------------------" << endl;
		cout << N << endl;
		int E = 0;
		for (int i = 0; i < N; ++i) {
			E += i;
		}
		cout << E << endl;
		for (int i = 0; i < N - 1; ++i) {
			for (int j = i + 1; j < N; ++j) {
				cout << i << " " << j << endl;
			}
		}
	}
	return 0;

}