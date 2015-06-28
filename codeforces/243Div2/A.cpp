#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,s;
    int vol[110];
    cin>>n>>s;
    for(int i = 0; i<n; i++){
        cin>>vol[i];
    }
    sort(vol, vol+n);
    int tt = 0;
    for(int i =0; i<n-1; i++){
        tt += vol[i];
    }
    if(tt>s){
        cout<<"NO\n";
    } else{
        cout<<"YES\n";
    }

    return 0;
}
