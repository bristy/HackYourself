// =====================================================================================
//
//       Filename:  rooms.cpp
//
//    Description:  http://www.hackerearth.com/intel-securitymcafee-hiring-challenge/algorithm/rooms-1/
//
//        Version:  1.0
//        Created:  Friday 19 September 2014 09:36:45  IST
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

#define MAX 100010
struct entry{
    int nr[2];
} A[MAX];

int comp(entry a, entry b){
    if(a.nr[1] == b.nr[1]){
        return a.nr[0] < b.nr[0];
    } else {
        return a.nr[1] < b.nr[1];
    }
}

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] ){
    int t;
    s(t);
    int n;
    int v;
    while(t--){
        s(n);
        REP(i, n){
            s(v);
            A[i].nr[0] = v;
        }

        REP(i, n){
            s(v);
            A[i].nr[1] = v + A[i].nr[0];
        }

        sort(A, A + n, comp);
        int ret = 1;
        int j = 0;
        FOR(i, 1, n){
            if(A[i].nr[0] >= A[j].nr[1]){ // selected dont conflict
                ret++;
                j = i;
            }
        }
        if(ret == 1){
            ret = n;
        } else {
            ret = n - ret;
        }
        printf("%d\n", ret);
    }

	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

