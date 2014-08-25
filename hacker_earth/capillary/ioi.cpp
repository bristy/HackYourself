/*
 * =====================================================================================
 *
 *       Filename:  ioi.cpp
 *
 *    Description:  http://www.hackerearth.com/capillary-hiring-challenge/algorithm/ioi-2050-2/
 *
 *        Version:  1.0
 *        Created:  Sunday 24 August 2014 04:41:08  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


//http://www.spoj.pl/problems/CSTREET/
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
#define INDEX(arr,ind) lower_bound(all(arr),ind)-arr.begin())
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())


/* fast Input*/
#define getcx getchar_unlocked
inline void inp( int &n )
{
	n=0;
	int ch=getcx();
	while( ch < '0' || ch > '9' ){ch=getcx();}
	while( ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;
typedef vector< PII > VPII;
/*Main Code*/

#define MAX 1001
int dist[MAX][MAX];
VPII tree[MAX];
class dsu{
	public:
		int parent;
		int rank;
};

vector <dsu> forest;

int findSet(int i){
	if (i!=forest[i].parent)
		forest[i].parent = findSet(forest[i].parent);
	return forest[i].parent;
	/*return (i==forest[i].parent) ? i:(forest[i].parent=findSet(forest[i].parent));*/

}

void unionSet(int i, int j){
	int x = findSet(i);
	int y = findSet(j);
		
	if(forest[x].rank>forest[y].rank){
		forest[y].parent = x;
	}
	else{
		forest[x].parent = y;
	       if(forest[y].rank == forest[x].rank) forest[y].rank++;	
	}
}

vector <pair< int, PII > > Edge;
int n;
int kruskal()
{
	//make set
	forest.resize(sz(Edge));
	REP(i,sz(Edge)){
		forest[i].parent = i;
		forest[i].rank = 0;
	}
	int ttc = 0;
	sort(all(Edge));
	for(int i = 0; i<sz(Edge); ++i){
		int u = Edge[i].second.first;
		int v = Edge[i].second.second;
		if(findSet(u) != findSet(v)){
			ttc = Edge[i].first;
			unionSet(u,v);
			tree[v].pb(mp(ttc, u));
			tree[u].pb(mp(ttc, v));
			//printf("Edge %d  %d  %d\n", u+1, v+1, ttc);
			//cout<<u+1<<" "<<v+1<<endl;
		}

	}
	return ttc;
}

void bfs(int start){
	dist[start][start] = 0;
	queue<int> q;
	q.push(start);
	int visited[MAX] = {0};
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		visited[u] = 1;
		for(int i = 0; i<(int)tree[u].size(); i++){
			int v = tree[u][i].second;
			if(visited[v] == 0){
				int cost = tree[u][i].first;
				dist[start][v] = dist[start][u] + cost;
				q.push(v);
			}
		}
	}
}

int main(){
	int t;
	inp(t);
	int p,m,u,v,w;
	int testCase = 1;
	while(t--){
		Edge.clear();
		REP(i, MAX){
			tree[i].clear();
		}
		s(n);
		s(p);
		s(m);
		REP(i,p){
			s(u);
			s(v);
			s(w);
			Edge.pb(mp(w,mp(u-1,v-1)));
		}
		kruskal();
		REP(i, n){
			bfs(i);
		}

		int a, b;
		printf("Case: %d\n", testCase);
		REP(i, m){
			s(a);
			s(b);
			printf("%d\n", dist[a-1][b-1]);
			//printf("%d\n", dist[b-1][a-1]);
		}
		testCase++;
	}
	return 0;
}

