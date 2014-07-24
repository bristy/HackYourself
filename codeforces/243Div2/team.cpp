#include<iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 100010
#define MOD 1000000007
long long C[MAX];
int A[MAX];
int main(){
    int n,k;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i =0; i<n; i++){
            cin>>A[i];
        }

        sort(A, A+n);


        long long ret = A[n-k];
        long long pp = 1;
        long long curr = n-k + 1;
        for(int i =n-k-1; i>=0; i--){

            ret = ret + A[i] * pp;
            ret %= MOD;
            pp *=  curr;
            pp %=  MOD;
            curr++;
        }

        cout<<ret<<endl;
    }

    return 0;
}
