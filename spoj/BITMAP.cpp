// =====================================================================================
//
//       Filename:  BITMAP.cpp
//
//    Description:  http://www.spoj.com/problems/BITMAP/
//
//        Version:  1.0
//        Created:  Wednesday 30 July 2014 08:47:05  IST
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
#define MAX 200


int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int bitmap[MAX][MAX];
int ret[MAX][MAX];
VPII whitePxl;
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] ){
    int N,M;
    int t;
    s(t);
    string str;
    while(t--){
        cin>>N>>M;
        whitePxl.clear();
    
        REP(i, N){
            
            cin>>str;
            REP(j, M){
                ret[i][j] = INF;
                bitmap[i][j] = str[j] - '0';
                if(bitmap[i][j] == 1){
                    whitePxl.pb(mp(i,j));
                    ret[i][j] = 0;
                }
            }
        }

        REP(i, int(whitePxl.size())){
            PII curr = whitePxl[i];
            queue<PII> queue;
            queue.push(curr);

            // bsf
            while(!queue.empty()){
                PII temp = queue.front();
                queue.pop();
                REP(z,4){
                    int xx = temp.first + di[z];
                    int yy = temp.second + dj[z];
                    if(xx >=0 && xx < N && yy >=0 && yy < M){
                        int dist = abs(xx - curr.first) +  abs(yy - curr.second);
                        if(dist < ret[xx][yy]){
                            ret[xx][yy] = dist;
                            queue.push(mp(xx,yy));
                        }
                    }
                }   
            }
            
        }

        REP(i, N){
            REP(j,M){
                if(j != 0){
                    printf(" ");
                }
                printf("%d", ret[i][j]);
                
            }
            printf("\n");
        }
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

