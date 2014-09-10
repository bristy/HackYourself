// =====================================================================================
//
//       Filename:  even_odd.cpp
//
//    Description:  http://www.hackerearth.com/multunus-hiring-challenge/algorithm/even-odd-5/
//
//        Version:  1.0
//        Created:  Sunday 07 September 2014 11:21:49  IST
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
LL APSum(LL a, LL n, LL d){
    return n*(2*a + (n - 1)*d)/2;
}

int
main ( int argc, char *argv[] ){
    int t;
    cin>>t;
    LL retE, retO, R, C;
    while(t--){
        retE = retO = 0LL;
        cin>>R>>C;
        LL norm = min(R, C);
        LL odd = (norm + 1)/2;
        LL even = norm / 2;
        retO = APSum(1, odd, 2);
        retE = APSum(2, even, 2);
        LL fac = max(0LL, R - C);
        if(fac > 0){
            retO += ((R+1)/2 - odd)*C;
            retE += (R/2 - even)*C;
        }
        cout<<retE<<" "<<retO<<"\n";
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 


