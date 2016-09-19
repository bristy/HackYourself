//http://en.wikipedia.org/wiki/Goldbach's_conjecture
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    bool blank = false;
    while(t--){
        int n;
        cin>>n;

        if(blank){
            cout<<endl;
        }

        if(n != 2){
            cout<<"Deepa";
        } else {
            cout<<"Arjit";
        }
        blank = true;
    }
    return 0;
}

