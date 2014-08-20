// =====================================================================================
//
//       Filename:  RepairWork.cpp
//
//    Description:  http://www.hackerearth.com/lendingkart-hiring-challenge/algorithm/repair-work-1/
//
//        Version:  1.0
//        Created:  Saturday 02 August 2014 03:20:41  IST
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
#define MAX 5001
double dp[MAX][MAX];

double dist(int x, int y, VI &pos){
   return sqrt(pos[y]-pos[x]+1);  
}
double findMin(int x, int y, VI &pos){
    if(x == y){
        return 1;
    }
    if(dp[x][y] != INF){
        return dp[x][y];
    }

    for(int i = x; i<=y; i++){
        double cost = min(dist(x, y, pos), dist(x, i, pos) +  dist(i+1, y, pos));
        if(dp[x][y]> cost){
            dp[x][y] = cost; 
        }
    }

    return dp[x][y];
}


void solve(){
    int n;
    string str;
    s(n);
    cin>>str;
    VI pos;
    REP(i, n){
        if(str[i] == '0'){
            pos.pb(i);
        }
    }

    int len = sz(pos);
    REP(i, len){
        REP(j, len){
            dp[i][j] = INF;
        }
    }

    printf("%.4f", findMin(0, sz(pos)-1, pos));

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

