// =====================================================================================
//
//       Filename:  TRT.cpp
//
//    Description:  http://www.spoj.com/problems/TRT/
//
//        Version:  1.0
//        Created:  Wednesday 08 October 2014 04:53:27  IST
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
#define MAX_N 2010

int memo[MAX_N][MAX_N];
int values[MAX_N];
int N;
// return treat on day d where treats between indeces l and r are left
int trt(int l, int r, int d){
    if(l < 0 || r >= N || l > r){
        return 0;
    }
    if(l == r){
        return values[l] * d;
    }
    if(memo[l][r] != -1){
        return memo[l][r];
    }

    int ll = trt(l + 1, r, d + 1) + values[l] * d;
    int rr = trt(l, r - 1, d + 1) + values[r] * d;
    memo[l][r] = max(ll, memo[l][r]);
    memo[l][r] = max(rr, memo[l][r]);
    return memo[l][r];
}
int
main ( int argc, char *argv[] ){
    REP(i, MAX_N){
        REP(j, MAX_N){
            memo[i][j] = -1;
        }
    }
    s(N);
    REP(i, N){
        s(values[i]);
    }
    printf("%d\n", trt(0, N - 1, 1));
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

