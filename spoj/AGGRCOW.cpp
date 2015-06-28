// =====================================================================================
//
//       Filename:  AGGRCOW.cpp
//
//    Description:  http://www.spoj.com/problems/AGGRCOW/
//
//        Version:  1.0
//        Created:  Thursday 09 October 2014 05:42:33  IST
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
#define MAX_N 100010
int pos[MAX_N];
int C, N;
bool canAssign(int dist){
    // i can always assing a cow on first barn
    int cows = C - 1;
    int barn = 1;
    int prev = 0;
    while(barn < N && cows > 0){
        if(pos[barn] - pos[prev] >= dist){
            // assing a cow here
            cows--;
            prev = barn;
        }
        barn++;
    }
    return cows <= 0; 
}

int
main ( int argc, char *argv[] ){
    int t;
    s(t);
    while(t--){
        s(N);
        s(C);
        REP(i, N){
            s(pos[i]);
        }
        sort(pos, pos + N);
        int lo = 0;
        int hi = INF;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            bool assign = canAssign(mid);
            if(assign){
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if(!canAssign(hi)){
            hi--;
        }
        printf("%d\n", hi);
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

