// =====================================================================================
//
//       Filename:  jungle.cpp
//
//    Description:  http://www.hackerearth.com/jda-hackathon/algorithm/jungle-run/
//
//        Version:  1.0
//        Created:  Saturday 21 June 2014 07:38:02  IST
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

int di[] = {0, -1, 0, 1};
int dj[] = {-1, 0, 1, 0};

/*Main Code*/
#define EXIT_SUCCESS 0
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
#define MAX_N 50
#define TREE -1
#define START 0
#define END 1
#define PATH  2
int grid[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int sI, sJ;
int eI, eJ;
int N;
void bfs(){
    queue<PII> buffer;
    buffer.push(mp(sI, sJ));
    dist[sI][sJ] = 0;
    while(!buffer.empty()){
        PII curr = buffer.front(); buffer.pop();
        if(visited[curr.first][curr.second] == 1){
            continue;
        }
        visited[curr.first][curr.second] = 1;
        REP(i,4){
            int ii = curr.first + di[i];
            int jj = curr.second + dj[i];
            if(ii >=0 && ii < N && jj >=0 && jj <N){
                if(grid[ii][jj] != TREE){
                    dist[ii][jj] = min(dist[ii][jj], dist[curr.first][curr.second]+1);
                    buffer.push(mp(ii, jj));
                }
            }

        }
    }
}
int
main ( int argc, char *argv[] ){
    
    char c;
    cin>>N;
    REP(i, N){
        REP(j, N){
            dist[i][j] = INF;
            visited[i][j] = 0;
            cin>>c;
            if(c=='S'){
                grid[i][j] = START;
                sI = i;
                sJ = j;
            } else if(c == 'E'){
                grid[i][j] = END;
                eI = i;
                eJ = j;
            } else if(c == 'P'){
                grid[i][j] = PATH;
            } else {
                grid[i][j] = TREE;
            }
        }
    }

    
    dist[sI][sJ] = 0;
    bfs();
    cout<<dist[eI][eJ];
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

