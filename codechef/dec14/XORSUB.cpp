#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1010
int A[MAX];
long long dp[MAX];
int main(){
    int t;
    scanf("%d", &t);
    int n, k;
    while(t--){
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &A[i]);
        }
        for(int i =0 ; i < n; i++){
            dp[i] = max(k, k ^ A[i]);
        }

        for(int i = 1; i<n; i++){
            for(int  j = 0; j < i; j++){
                dp[i] = max(dp[i], dp[j]^A[i]);
            }
        }

        long long ret = 0;
        for(int i = 0; i < n; i++){
            ret = max(ret, dp[i]);
        }

        printf("%lld\n", ret);
    }
}
