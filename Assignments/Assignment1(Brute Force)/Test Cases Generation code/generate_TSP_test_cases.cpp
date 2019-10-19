#include <iostream>
using namespace std;
#define N 11
int main(){
	cout << N << " 0" << endl;
	int E = 0;
	for(int i = 0; i < N; ++i){
		E+=i;
	}
	cout << E << endl;
	for(int i = 0; i < N-1; ++i){
		for(int j = i+1; j < N; ++j){
			cout << i << " " << j << " 5" << endl;
		}
	}
}