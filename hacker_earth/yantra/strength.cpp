#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define M 1000000007
#define MAX_N 100010
int A[MAX_N];


int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &A[i]);
        }
        sort(A, A+n);
        long long ret = 0;
        long long sum = 0;
        for(int i =1; i<n; i++){
            sum += A[i-1];
            ret = ret + ((long long)i * A[i] - sum);
            ret %= M;
        }

        ret = (ret * A[n-1])%M;
        cout<<ret<<"\n";
    }
}
