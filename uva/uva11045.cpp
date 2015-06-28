// =====================================================================================
//
//       Filename:  uva11045.cpp
//
//    Description:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1986
//
//        Version:  1.0
//        Created:  Friday 05 September 2014 12:50:18  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================



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
#define EXIT_SUCCESS 0
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
#define MAX_V 50
int res[MAX_V][MAX_V];
VI  bfsTree;
map<string, int> code;

int mf, f, source, sink;

void preprocess(){
    code["XS"] = 1;
    code["S"] = 2;
    code["M"] = 3;
    code["L"] = 4;
    code["XL"] = 5;
    code["XXL"] = 6;
}

void augment(int curr, int minEdge){
    if(curr == source){
        f = minEdge;
        return;
    } else if(-1 != bfsTree[curr]){

        // augment recursively
        augment(bfsTree[curr], min(minEdge, res[bfsTree[curr]][curr]));
        // subtract minEdge in forward edge
        res[bfsTree[curr]][curr] -= f;
        // add minEdge in backward edge
        res[curr][bfsTree[curr]] += f;
    }

}
int edmondKarp(){
    mf = 0;
    f = 0;
    while(true){
        f = 0;
        VI dist(MAX_V, INF);
        queue<int> q;
        q.push(source);
        dist[source] = 0;

        // init bfs tree 
        bfsTree.clear();
        bfsTree.assign(MAX_V, -1);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            // reach to sink exit from here
            if(u == sink){
                break;
            }
            REP(v, MAX_V){
                if(res[u][v] > 0 && INF == dist[v]){
                    dist[v] = dist[u] + 1;
                    bfsTree[v] = u;
                    q.push(v);
                }
            }
        }
        
        augment(sink, INF);
        // if no path in residual graph exit
        if(!f){
            break;
        }
        mf += f; // add flow to max flow
    }

    return mf;
}

int
main ( int argc, char *argv[] ){
    preprocess();
    int t;
    s(t);
    int n, m;
    while(t--){
        REP(i, MAX_V){
            REP(j, MAX_V){
                res[i][j] = 0;
            }
        }
        
        cin>> n>>m;
        sink = m + 6 + 1; // 6 t-shirts size, m person     
        source = 0;
        FOR(i, 1, 7){
            res[0][i] = n/6;
        }
        string tshirt;
        for(int i = 7; i<m+7; i++){
            // first choice
            cin>>tshirt;
            res[code[tshirt]][i] = 1;
            
            // second choice
            cin>>tshirt;
            res[code[tshirt]][i] = 1;
            
            // connection with sink
            res[i][sink] = 1;
        }

        int flow = edmondKarp();
        if(flow == m){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

