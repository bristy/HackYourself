
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
/*Main Code*/

#define MAX 11
class Egalitarianism3Easy{
    public:
        int dist[MAX][MAX];
        VPII tree[MAX];
        int maxCities(int n, vector <int> a, vector <int> b, vector <int> len){
            REP(i, n - 1){
                int x = a[i] - 1;
                int y = b[i] - 1;
                int l = len[i];
                tree[x].pb(mp(y, l));
                tree[y].pb(mp(x, l));
            }
            REP(i, MAX){
                dist[i][i] = 0;
            }
            // calc all pair path
            REP(i, n){
                dfs(i, i, i);
            }
            
           /* 
            REP(i, n){
                REP(j, n){
                    printf("i = %d j = %d cost = %d\n", i + 1, j + 1, dist[i][j]);
                }
            }
            */
            int maxk = 0;
            REP(grp, 1<<n){
                bool ok = true;
                int l = -1;
                REP(i, n){
                    REP(j, n){
                        if(((1<<i) & grp) && ((1<<j) & grp) && i != j){ // if both i and j are in current group
                            if(l != -1){
                                ok = ok && (l == dist[i][j]);
                                
                            } else {
                                l = dist[i][j];
                            }
                        
                        }
                    }
                }
                if(ok){
                    int k = 0;
                    REP(j, n){
                        if((1<<j) & grp){
                            k++;
                        }
                    }
                    /*
                    if(k > maxk){
                        printf("%d\n", grp);
                    }
                    */
                    maxk = max(maxk, k);
                }
            }
            return maxk;
        }

        // dfs to find dist frim calling vertices
        void dfs(int start, int u, int parent){
            for(VPII::iterator it = tree[u].begin(); it != tree[u].end(); it++){
                int v = it->first;
                int cost = it->second;
                if(v != parent){ // if u is not back edge
                    dist[start][v] = dist[start][u] + cost;
                    dfs(start, v, u);
                }
            }
        }
};
