// =====================================================================================
//
//       Filename:  PPATH.cpp
//
//    Description:  http://www.spoj.com/problems/PPATH/
//
//        Version:  1.0
//        Created:  Saturday 11 October 2014 12:51:07  IST
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
#define MAX_N 10001
VI primes; // four digit primes
VI graph[MAX_N];
int dist[MAX_N];
int visited[MAX_N];
int parent[MAX_N];
bool atOneStep(int a, int b){
    int stp = 0;
    while(a && b){
        if(a % 10 != b % 10){
            stp++;
        }

        a /= 10;
        b /= 10;
    }

    return stp == 1;
}

int isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

void preprocess(){
    FOR(i, 1001, MAX_N){
        if(isPrime(i)){
            primes.pb(i);
            REP(j, sz(primes)){
                if(atOneStep(i, primes[j])){
                    graph[i].pb(primes[j]);
                    graph[primes[j]].pb(i);
                }
            }
        }
    }
}

int bfs(int start, int end){
    fill(dist, 0);
    fill(visited, 0);
    fill(parent, 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    parent[start] = start;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        // printf("currently at = %d\n", u);
        if(u == end){
            return dist[u];
        }
        for(int i = 0; i < sz(graph[u]); i++){
            int v = graph[u][i];
            if(!visited[v]){
                q.push(v);
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }

    return INF; // unrechable
}

void displayPath(int s){
    while(s != parent[s]){
        printf("   %d   ", s);
        s = parent[s];
    }
    printf("   %d   ", s);
}

int
main ( int argc, char *argv[] ){
    preprocess();
    // printf("%d", atOneStep(1033, 1733));
    int t;
    s(t);
    while(t--){
        int a, b;
        s(a); s(b);
        int ret = bfs(a, b);
        if(ret == INF){
            printf("Impossible\n");
        } else{
            printf("%d\n", ret);
        }
        // displayPath(b);
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

