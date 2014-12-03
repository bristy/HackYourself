
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
#include<sstream>
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
#define MAX 50
/*Main Code*/
class Marketing{
    bool mat[MAX][MAX];
    int color[MAX];
    const int NO_COLOR = 0;
    const int WHITE = 1;
    const int BLACK = 2;
    int err = 0; // no error
    public:
        long long howMany(vector <string> compete){
            REP(i, MAX){
                color[i] = NO_COLOR;
                REP(j, MAX){
                    mat[i][j] = false;
                }
            }
            LL ret = 1;
            int len = compete.size();
            REP(i, len){
                istringstream is(compete[i]);
                int n;
                while(is >> n){
                    mat[i][n] = mat[n][i] = true;
                } 
            }
            REP(i, len){
                if(color[i] == NO_COLOR){
                    dfs(i, WHITE);
                    if(err){
                        return -1;
                    }
                    ret *= 2;
                }
            }
            return ret;
        }
        void dfs(int s, int c){
            if(color[s] != NO_COLOR){
                if(color[s] != c){
                    err = 1;
                }
                return;
            } else {
                color[s] = c;
                int other = 3 - c;
                REP(i, MAX){
                    if(mat[s][i]){
                        dfs(i, other);
                    }
                }
            }
        }
};
