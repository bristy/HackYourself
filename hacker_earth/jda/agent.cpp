
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
#define maX(a,b) (a>b?a:b)
#define miN(a,b) (a<b?a:b)
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) lower_bound(all(arr),ind)-arr.begin()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;
typedef vector< PII > VPII;


#define MAX_N 110

map<int, int> p; // parent map to reconstruct path
int f, s, t; // global variables

VPII AdjList [MAX_N];
int AdjMat [MAX_N][MAX_N];

void augmentPath(int v, int minEdge) {
    if (v == s) { // managed to get back to source
        f = minEdge; // minEdge of the path
        return;
    }else if (p.count(v)) { // augment if there is a path
        // we need AdjMat for fast lookup here
        augmentPath(p[v], min(minEdge, AdjMat[p[v]][v]));
        AdjMat[p[v]][v] -= f; // forward edges -> decrease
        AdjMat[v][p[v]] += f; // backward edges -> increase
    }
}
void edmond_karp(){
    int max_flow = 0;
    while (1) { // this will be run max O(VE) times
        f = 0;
        queue<int> q; map<int, int> dist; // O(E) BFS and record path p
        q.push(s); dist[s] = 0; // start from source
        while (!q.empty()) {
            int u = q.front(); q.pop(); // queue: layer by layer!
            if (u == t) break; // modification 1: reach sink t, stop BFS
            tr(AdjList[u], v) // for each neighbours of u
            // modification 2: also check AdjMat as edges may disappear
            if (AdjMat[u][v->first] > 0 && !dist.count(v->first)) {
                dist[v->first] = dist[u] + 1; // then v is reachable from u
                q.push(v->first); // enqueue v for next steps
                p[v->first] = u; // modification 3: parent of v->first is u
            }
        }
        augmentPath(t, INF); // path augmentation in O(V)
        if (f == 0) break; // seems that we cannot pass any more flow
        max_flow += f;
    }
    printf("Max flow = %d\n", max_flow);
}

int main(){
  int pass;
  int n,r;
  cin>>n>>r;
  int a, b, w;
  REP(i, MAX_N)REP(j, MAX_N)AdjMat[i][j] = INF;
  REP(i,r){
    cin>>a>>b>>w;
    a--; b--;
    AdjMat[a][b] = w;
    //AdjMat[b][a] = w;
    AdjList[a].pb(mp(b,w));
    //AdjList[b].pb(mp(a,w));

  }
  cin>>s>>t>>pass;
  s--; t--;
  edmond_karp();
}
