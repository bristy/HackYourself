#include <iostream>
using namespace std;

#define M 1000000007
/* this function calculates (a*b)%c taking into account that a*b might overflow */
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

long long inversemod(long long a){
    return mulmod(a, M-2, M);
}
int main(){
    int n;
    cin>>n;

    long long ret = 1;
    for(int i = 0; i<4;i++){
        ret = (ret * (n-i))%M;
    }
    cout<<ret<<endl;
        ret = (ret * inversemod(24))%M;


    cout<<ret;
}
