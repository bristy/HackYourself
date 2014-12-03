// =====================================================================================
//
//       Filename:  haunted.cpp
//
//    Description:  http://www.hackerearth.com/taxiforsure-hiring-challenge/algorithm/haunted/
//
//        Version:  1.0
//        Created:  Saturday 29 November 2014 12:11:50  IST
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

#define MAX 100001
int N, M;
int nums[MAX];


void solve(){

    // read input
    s(N);s(M);
    REP(i, N){
        s(nums[i]);
    }

    // main logic starts here
    map<int, int> record; // holds the value and its occurence
    set<PII> best; // hold pair of <occurence, value>
    map<int, int>:: iterator mapIt;
    REP(i, N){
        int item = nums[i];
        mapIt = record.find(item);
        if(mapIt != record.end()){ // already has
            PII curr = mp(mapIt->second, mapIt->first);
            mapIt->second++;
            PII newPair = mp(mapIt->second, mapIt->first);
            best.insert(newPair);
            best.erase(best.find(curr));
        } else { // new item
            record[item] = 1;
            best.insert(mp(1, item));
        }
        PII ret = *best.rbegin();
        printf("%d %d\n", ret.second, ret.first);
    }
}
int
main ( int argc, char *argv[] ){
    
    solve();
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

