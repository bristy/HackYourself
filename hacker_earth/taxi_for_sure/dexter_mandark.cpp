// =====================================================================================
//
//       Filename:  dexter_mandark.cpp
//
//    Description:  http://www.hackerearth.com/taxiforsure-hiring-challenge/algorithm/dexter-and-mandark-1/
//
//        Version:  1.0
//        Created:  Saturday 29 November 2014 12:46:58  IST
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

#define MOD 1000000007
#define MAX 1001
int dp[MAX][MAX];
int N, M;
int solve(int day, int D){
    
    int dexter = D;
    int mandark = day - D;
    if(day == N){
        return dexter >= mandark * M;
    }

        // if at any step we dont full fill condition return 
    if(dexter < mandark * M){
        return 0;
    }
    // alredy computed
    if(dp[day][D] != -1){
        return dp[day][D];
    }

    
    dp[day][D] =  (solve(day + 1, D + 1) + solve(day + 1, D)) % MOD;
    return dp[day][D];

}

int
main ( int argc, char *argv[] ){
    int t;
    s(t);
    while(t--){
        s(N); s(M);
        fill(dp, -1);
        printf("%d\n",solve(0, 0));
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

