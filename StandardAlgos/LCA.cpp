// =====================================================================================
//
//       Filename:  LCA.cpp
//
//    Description:  LCA using binary lift up method
//                  O(NlogN) processing and O(logN) query time
//
//        Version:  1.0
//        Created:  Sunday 13 April 2014 09:52:02  IST
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
#define MAX_N 1001
#define MAX_L 10
VI g[MAX_N];
int up[MAX_N][MAX_L];
int tin[MAX_N], tout[MAX_N];
int timer;
int l, n;

// ===  FUNCTION  ======================================================================
//         Name:  dfs
//  Description:  
// =====================================================================================
    void
dfs ( int v, int p ){
    up[v][0] = p;
    tin[v] = ++timer;
    FOR(i, 1, l+1){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    tr(g[v], c){
        if(*c != p){
            dfs(*c, v);
        }
    }
    tout[v] = ++timer;
    return ;
}		// -----  end of function dfs  -----


// ===  FUNCTION  ======================================================================
//         Name:  upper
//  Description:  return true if a is ancestor of b else false
// =====================================================================================
    bool
upper ( int a, int b){

    return tin[a]<=tin[b] && tout[a]>=tout[b];
}		// -----  end of function upper  -----



// ===  FUNCTION  ======================================================================
//         Name:  lca
//  Description:  
// =====================================================================================
    int
lca ( int a, int b ){
    
    if(upper(a, b)){
        return a;
    }
    if(upper(b, a)){
        return b;
    }

    for(int i = l; i>=0; i--){
        if(!upper(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}		// -----  end of function lca  -----


// ===  FUNCTION  ======================================================================
//         Name:  solve
//  Description:  
// =====================================================================================
    void
solve ( ){
	timer = 0;
    int m, node;
    // read n
    s(n);
    // read g
    REP(i,n){
        
        s(m);
        g[i].resize(m);
        REP(j,m){
            
            s(node);
            g[i][j] = (node -1);
        }
    }
    l = 1;
    while((1<<l)<=n) l++;
    
    dfs(0, 0);

    // process queries
    int q, v, w;
    s(q);
    REP(i,q){
        s(v);s(w);
        printf("%d\n", lca(v-1,w-1)+1);
    }
    return ;
}		// -----  end of function solve  -----
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] ){
	int t, i = 1;
    for(s(t); t; t--){
        printf("Case %d:\n", i++);
        solve();
    }
    return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

