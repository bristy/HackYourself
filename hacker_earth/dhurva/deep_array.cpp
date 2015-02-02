#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100001
int n, m;
int A[MAX];
int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &m);
    int val;
    for(int i = 0; i < m; i++){
        scanf("%d", &val);
        for(int j = 0; j< n; j++){
            if(A[j] > val){
                A[j]--;
            }
        }
    
    }
    // print array
    for(int i = 0; i < n; i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    return 0;
}
