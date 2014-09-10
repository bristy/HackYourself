// =====================================================================================
//
//       Filename:  race.cpp
//
//    Description:  http://www.hackerearth.com/multunus-hiring-challenge/algorithm/the-amazing-race-1/
//
//        Version:  1.0
//        Created:  Monday 08 September 2014 12:01:53  IST
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
#define MAX_K 1000010
#define MAX_N 100010

#define MOD 1000000007
int A[MAX_N];
int C[MAX_K];
int
main ( int argc, char *argv[] ){
    int t;
    s(t);
    while(t--){
        memset(C, 0, MAX_K);
        int n;
        s(n);
        REP(i, n){
            s(A[i]);
            C[A[i]]++;
        }

        FOR(i, 1, MAX_K){
            C[i] += C[i-1];
            C[i] %= MOD;
        }
        int best = -1;
        int idx;
        REP(i, n){
            LL X = C[A[i]];
            int curr = X*(i+1)%MOD;
            if(best <= curr){
                best = curr;
                idx = i+1; 
            }
        }
        cout<< idx<<"\n";
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

