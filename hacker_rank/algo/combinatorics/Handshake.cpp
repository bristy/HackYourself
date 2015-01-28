#include <iostream>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    long long n ;
    cin>>n;
    n = (n-1)*n/2;
    cout<<n<<endl;
  }
}
