#include <iostream>
using namespace std;

#define MOD 1234567
int main(){
  int t;
  int n;
  long long ret;
  int tmp;
  cin >> t;
  while(t--){
    cin>>n;
    ret = 1;
    while(n-- > 1){
      cin>>tmp;
      ret = (ret * tmp % MOD) % MOD;
    }
    cout<<ret <<endl;
  }
}
