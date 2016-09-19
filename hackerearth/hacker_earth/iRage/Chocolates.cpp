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
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;

// main code start from here

int choc[201];
int visited[201];
vector< pair<int, PII> > edge;


int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


void solve() {
    int u, v, w;

    int N, M;
    cin>>N>>M;
    REP(i, N - 1){
        cin>>choc[i];
        visited[i] = 0;
    }
    edge.clear();
    REP(i, M) {
        cin>>u>>v;
        w = gcd(choc[u - 1], choc[v - 1]);
        edge.pb(mp(-w, mp(u - 1, v - 1)));
    }
    sort(all(edge));
    int ret = 0;
    REP(i, M) {
        pair <int, PII> curr = edge[i];
        u = curr.second.first;
        v = curr.second.second;
        w = -curr.first;
        if(!visited[u] && !visited[v] && (u + v) % 2 > 0){
            visited[u] = visited[v] = 1;
            ret += w;
        }
    }
    cout<<ret<<"\n";
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
