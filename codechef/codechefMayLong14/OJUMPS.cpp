#include <iostream>

using namespace std;
int main(){
    long long int a ;
    cin>>a;
    a = a%6;
    if(a == 2 || a == 4 || a == 5){
        cout<<"no";
    } else {
        cout<<"yes";
    }

    return 0;
}
