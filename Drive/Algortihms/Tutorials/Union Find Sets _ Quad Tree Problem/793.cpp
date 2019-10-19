#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> pset;
void initSet(int N){
    pset.assign(N+1,0);
    for ( int i=0;i<=N;i++){
        pset[i] = i;
    }
}
int findSet(int i){
    if (pset[i] == i) return i;
    pset[i] = findSet(pset[i]);
    return pset[i];
}
bool isSameSet(int i,int j){
    return findSet(i) == findSet(j);
}
void unionSet(int i, int j){
    pset[findSet(i)] = findSet(j);
}
int main() {
    freopen("A.in", "r", stdin);
    int t;
    scanf("%d\n",&t);

    while(t--){
        int N;
        scanf("%d\n",&N);
        initSet(N);
        string line;
        getline(cin,line);
        char type;
        int i,j;
        int success = 0;
        int unsuccess = 0;
        while(line.length() > 3){
            sscanf(line.c_str(),"%s %d %d",&type,&i,&j);
            if (type == 'c'){
                unionSet(i,j);
            }else{
                if (isSameSet(i, j)) success++;
                else unsuccess++;
            }
            getline(cin,line);

        }
        printf("%d,%d\n\n",success,unsuccess);
    }
    return 0;
}