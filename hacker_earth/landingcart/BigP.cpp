// =====================================================================================
//
//       Filename:  BigP.cpp
//
//    Description:  http://www.hackerearth.com/lendingkart-hiring-challenge/algorithm/big-p-and-party-1/
//
//        Version:  1.0
//        Created:  Saturday 02 August 2014 02:30:25  IST
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
VVI graph;
void solve(){
    int A, B;
    cin>>A>>B;
    graph.resize(A);

    REP(i, B){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    int dist[A];
    int visited[A];
    REP(i,A){
        visited[i] = 0;
        dist[i] = INF;
    }
    //fill(visited, 0);
    //fill(dist, INF); 
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        if(!visited[curr]){
            // mark v as visited
            visited[curr] = 1;
            for(VI :: iterator c = graph[curr].begin(); c != graph[curr].end(); c++){
                int v = *c;
                int cost = dist[curr]+1;
                //cout<<"At "<<v<< "  dist  "<< dist[v]<<endl;
                //cout<<"  visited v "<<visited[v]<<endl;
                if(!visited[v] && cost < dist[v]){
                    dist[v] = cost;
                    q.push(v);
                }
            }
        }
    }

    FOR(i, 1, A){
        printf("%d\n", dist[i]);
    }

}

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] ){
    solve();
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

