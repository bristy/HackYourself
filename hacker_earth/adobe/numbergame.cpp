//Data Structure includes
#include<vector>
#include<bitset>
//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define s(n) scanf("%d",&n)
#define all(c) (c).begin(), (c).end()
#define maX(a,b) (a>b?a:b)
#define miN(a,b) (a<b?a:b)
#define INDEX(arr,ind) lower_bound(all(arr),ind)-arr.begin())
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

typedef vector<int> VI;
typedef long long ll;
/*Main Code*/
#define MAX_N 1000000010


int main(){
    int t;
    s(t);
    int n, m;
    while(t--){
        s(n); s(m);
        int ans[m-n+1];
        memset(ans,1,sizeof(ans));

        int i;
        for(int it = 2; (it<=(sqrt(m)+1));it++){
            int mv = (it)*(it);
           for(i =0; i<=(m-n);i++){
                if((i+n)%mv==0){
                    //cout<<"it   "<<it<<"  i   "<<i<<endl;
                    break;
                }

            }

            for(int j = i; j<=(m-n); j=j+mv)
            if(ans[j]){

                ans[j] = 0;
            }
        }
        int ret = 0;
        REP(i,m-n+1)if(ans[i])ret++;
        printf("%d\n", ret);
    }
    return 0;
}
