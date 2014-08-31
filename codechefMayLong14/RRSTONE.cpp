#include <iostream>
#include <cmath>
using namespace std;
#define INF 1e10
#define MAX_N 100010
typedef long long LL;
LL num[MAX_N];
int main(){
    LL mx = -INF;
    int N, K;
    cin>>N>>K;
    int turn = K&1;
    if(K>0 && !turn){
        turn = 2;
    }

    for(int i = 0; i<N; i++){
        cin>>num[i];
        mx = max(mx, num[i]);
    }
    LL temp = -INF;
    for(int t = 0; t<turn; t++){
       temp = -INF;
       for(int i = 0; i<N; i++){
            num[i] = mx - num[i];
            temp = max(temp, num[i]);
        }
        mx = temp;
    }

    bool blank = false;

    for(int i = 0; i<N; i++){
        if(blank)cout<<" ";
        blank = true;
        cout<<num[i];
    }
    return 0;
}
