//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define fill(a,v) memset(a, v, sizeof a)
#define sz(a) int((a).size())
#define INF (int)1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define all(c) (c).begin(), (c).end()
#define gcd __gcd
#define maX(a,b) (a>b?a:b)
#define miN(a,b) (a<b?a:b)
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) lower_bound(all(arr),ind)-arr.begin())
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;
#define MAX 100010
#define MOD 1000000007


struct node{
    int idx;
    int mx;
};


node T[4 * MAX];




int A[MAX];
int sqrtMax[MAX];
int sqrtMaxIdx[MAX];
int n;
int len;


node combine(node l, node r){
    node ret = l;
    if(ret.mx <= r.mx){
        ret = r;
    }

    return ret;

}

void init(int k, int lo, int hi){
    if(lo == hi){
        T[k].idx = lo;
        T[k].mx = A[lo];
        return;
    }
    
    int mid = (lo + hi) / 2;
    int next = k << 1;
    init(next, lo, mid);
    init(next + 1, mid + 1, hi);
    T[k] = combine(T[next], T[next + 1]);
    return;

}

node query(int k, int lo, int hi, int qlo, int qhi){
      
	if(lo==qlo && hi==qhi){
        return T[k];
    }
	int mid=(lo+hi)>>1;
	int next=k<<1;
	
    if(mid>=qhi){
        return query(next, lo, mid, qlo, qhi);
    }
	if(mid<qlo){
        return query(next+1, mid+1, hi, qlo, qhi);
    }
	return combine(
		query(next, lo, mid, qlo, mid),
		query(next+1, mid+1, hi, mid+1, qhi)
		);
}


int getMax(int l, int r){
    node ret = query(1, 0, n - 1, l, r);
    return ret.idx;    
}

void deb(){
   s(n);
   len = sqrt(n) + 1;
   REP(i, n){
        s(A[i]);
   }
   init(1, 0, n - 1);
}

void solve(){
    deb();
    if(n <= 2){
        printf("0\n");
        return;
    }
    
    int l = 0;
    int r;
    while(l < n-1 && A[l] < A[l + 1]){
        l++;
    }
    
    LL ret = 0;
    while(l + 1 < n){
        r = getMax(l + 1, n - 1);
        //printf("%d %d\n", l, r);
        int base = miN(A[l], A[r]);
        while(l < r){
            if(A[l] < base){
                ret += base - A[l];
            }
            l++;
        
        }
        ret %= MOD;
    }


    printf("%lld\n", ret % MOD);

}

int main(){
    int t;
    s(t);
    while(t--){
        solve();
    }
}
