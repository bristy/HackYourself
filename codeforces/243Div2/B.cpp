#include <iostream>

using namespace std;

#define MAX 110
int n, m;
int mat[MAX][MAX];

bool is same(int r1, int r2){

    for(int i = 0; i<m; i++){
        if(mat[r1][i] != mat[r2][i]){
            return false;
        }
    }
    return true;
}


