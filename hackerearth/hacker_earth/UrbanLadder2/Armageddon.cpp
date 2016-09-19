#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define MAX 100010
#define DIV 6
#define MOD 1000000007
long long  dp[MAX][DIV];
void solve(string s) {
    int n = s.length();
    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < DIV; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        int c = s[i] - '0';
        c %= DIV; 
        if(i == 0){
            dp[i][c] = 1;

        } else {
            // dont consider s[i]
            for(int j = 0; j < DIV; j++) {
                dp[i][j] = dp[i - 1][j] % MOD;
            }
            // consider s[i]
             
            for(int j = 0; j < DIV; j++) {
                int rem = (j * 10 + c) % DIV;
                dp[i][rem] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }
    }
    
    cout<<dp[n - 1][0] - 1<<"\n";
} 

int main() {
    int t;
    string input;
    cin>>t;
    while(t--) {
        cin>>input;
        solve(input);

    }
}
