#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    const long long MAX = 10000000010;
    int t;
    cin>>t;
    vector<long long> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    for(int i = 1; fibo[i]<MAX; i++){
        fibo.push_back(fibo[i]+fibo[i-1]);
    }
    long long n;
    while(t--){
        cin>>n;
        if(binary_search(fibo.begin(), fibo.end(), n)){
            cout<<"IsFibo\n";
        } else {
            cout<<"IsNotFibo\n";
        }
    }
    return 0;
}
