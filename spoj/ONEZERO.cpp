// =====================================================================================
//
//       Filename:  ONEZERO.cpp
//
//    Description:  http://www.spoj.com/problems/ONEZERO/
//
//        Version:  1.0
//        Created:  Sunday 12 October 2014 10:25:57  IST
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

#define MAX_N 20010
typedef pair<string, LL> PSL;
string ret;

void bfs(LL n){
    if(n == 1){
        ret = "1";
    }
    queue<PSL> s;
    string curr = "1";
    LL rem = 1;
    s.push(mp(curr, rem));
    while(!s.empty()){
        PSL p = s.front(); s.pop();
        curr = p.first;
        rem = p.second;
        LL tmp = rem;
        if(tmp % n == 0){
            // we have reached the number
            ret = curr;
            return;
        }
        
        // add 0 to remainder
        tmp = tmp * 10 + 0;
        tmp %= n;
        s.push(mp(curr + "0", tmp));
        
        // add 1 to remainder
        tmp = rem;
        tmp = tmp * 10 + 1;
        tmp %= n;
        s.push(mp(curr + "1", tmp));
    }
}

int
main ( int argc, char *argv[] ){
    int t;LL n;
    s(t);
    while(t--){
        sl(n);
        bfs(n);
        cout<<ret<<"\n";
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

