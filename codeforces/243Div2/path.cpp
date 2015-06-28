#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX 110

int A[MAX][MAX];
int dp[MAX][MAX];
int  main(){
    int n,m;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(A, 0, sizeof(A));
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>A[i][j];
            }
        }

        dp[0][0] = 1;
        int iii, jjj;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                iii = i+1;
                if(iii < n && A[i][j]<A[iii][j] && dp[i][j] > 0){
                    dp[iii][j] = dp[i][j] + 1;
                }

                jjj = j+1;
                if(jjj < m && A[i][j] < A[i][jjj] && dp[i][j]){
                    dp[i][jjj] = dp[i][j] + 1;
                }
            }
        }
        int ret = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ret = max(ret, dp[i][j]);
            }
        }

        cout<<ret<<endl;

    }

    return 0;
}
