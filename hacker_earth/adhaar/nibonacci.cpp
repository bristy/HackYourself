// =====================================================================================
//
//       Filename:  nibonacci.cpp
//
//    Description:  http://www.hackerearth.com/aadhaar-hackathon-screening-test/problems/4bff190d5a938ed7390ee0cfae24ff10/
//
//        Version:  1.0
//        Created:  Tuesday 02 December 2014 07:39:28  IST
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


int modulo(int a, int b){
    if(b == 0){
        return 1;
    }
    LL temp = modulo(a, b >> 1);
    temp = (temp * temp) % MOD;
    
    if(b & 1){
        temp = (temp * a) % MOD;
    }
    return temp;
}

void solve(){
    int n;
    s(n);
    n = modulo(2, n);
    n = (n + MOD - 1) % MOD;
    printf("%d\n", n);
}

int
main ( int argc, char *argv[] ){
    int t; s(t);
    while(t--){
        solve();
    }

	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 


