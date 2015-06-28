// =====================================================================================
//
//       Filename:  TSHIRTS.cpp
//
//    Description: http://www.codechef.com/problems/TSHIRTS 
//
//        Version:  1.0
//        Created:  Wednesday 24 September 2014 11:28:40  IST
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
int n;
const int MAX_T = 101;
const int MAX_N = 10;
LL dp[1 << MAX_N][MAX_T];
VI have[MAX_T];

int rec(int mask, int tid){
    if(tid <= 0){
        // we have used all tshirts
        return mask == (1 << n) - 1;
    }
   
    if(dp[mask][tid] != -1){
        // we have calculated it earlier
        return dp[mask][tid];
    }

    // do not assign tid t shirt to any one
    dp[mask][tid] = rec(mask, tid - 1); 
    // try to assign tis t-shirt to people have it
    // and dont assigned any t-shirt yet
    tr(have[tid], it){
        int p = *it;
        if(((1 << p) & mask) == 0){
            // we have not assign a tshist to p
            dp[mask][tid] += rec((1 << p) | mask, tid - 1);
            dp[mask][tid] %= MOD;
        }
    }
    return dp[mask][tid];
}

int
main ( int argc, char *argv[] ){
    int t;
    s(t);
    while(t--){
        s(n);
        REP(i, MAX_T){
            have[i].clear();
        }
        fill(dp, -1);
        char ss[10000];
	    for(int i = 0; i < n; ++i) {
            scanf(" %[^\n]", ss);
            int temp = 0;
 
            for (int j = 0; j < (int)strlen(ss); ++j) {
                if (ss[j] == ' ') {
                    have[temp].push_back(i);
                    temp = 0;
                } else {
                    temp = temp * 10 + ss[j] - '0';
                }
            }
            have[temp].push_back(i);
        }        
        cout<<rec(0, MAX_T - 1)<<"\n";
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

