// =====================================================================================
//
//       Filename:  GNYR09F.cpp
//
//    Description:  http://www.spoj.com/problems/GNYR09F/
//
//        Version:  1.0
//        Created:  Monday 20 October 2014 04:00:09  IST
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
#define MAX 110
int dp[MAX][MAX][2]; // state(n, k, b)

int solve(int pos, int k, int prev){
    if(k < 0 ){
        return 0;
    }
    if(pos < 0){
        return k == 0 ? 1 : 0;
    }

    int &ret = dp[pos][k][prev];
    if(ret != -1){
        return ret;
    }

    ret = 0;
    if(prev == 1){
        ret += solve(pos - 1, k - 1, 1) + solve(pos - 1, k , 0);
    } else {
        ret += solve(pos -1, k, 1) + solve(pos -1, k , 0);
    }
    return ret;
}

int
main ( int argc, char *argv[] ){
    int t, test;
    int n, k;
    s(t);
    while(t--){
        s(test);
        s(n);
        s(k);
        fill(dp, -1);
        
        printf("%d %d\n", test, solve(n - 2, k, 0) + solve(n - 2, k, 1));
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

