// =====================================================================================
//
//       Filename:  PT07Y.cpp
//
//    Description:  http://www.spoj.com/problems/PT07Y/
//
//        Version:  1.0
//        Created:  Tuesday 29 July 2014 08:46:54  IST
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
const int MAX = 10010;
int N, M;
VVI graph;
int visited[MAX];

bool  dfs(int start, int parent){
    // mark current as visited
    visited[start] = true;
    tr(graph[start], i){
        int v = *i;
        // if adjacent is not visited
        if(visited[v] == 0){
           if(dfs(v, start)){
                return true;
            }
        } else if(v != parent){
            // if adjacent visited and not the parent of currr node
            return true;
        }
    }

    return false;
}

void solve(){
    fill(visited, 0);
    bool istree = !dfs(0, -1);
    //cout<<istree<<endl;
    if(istree == true){
        REP(i,N){
            if(visited[i] == 0){
                istree = false;
                break;
            }
        }
    }
    if(istree){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
}
int
main ( int argc, char *argv[] ) {
    cin>>N>>M;
    int a, b;
    graph.resize(N);
    REP(i, M){
        cin>>a>>b;
        a--;b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    solve();    
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

