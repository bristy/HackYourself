#include <iostream>

using namespace std;
int main(){
  int n;
  cin>>n;
  int ret = 0;
  int prev = -1;
  int crr;
  while(n--){
    cin>>crr;
    if(prev != crr){
      ret++;
    }
    prev = crr;
  }
  cout<<ret;
}
