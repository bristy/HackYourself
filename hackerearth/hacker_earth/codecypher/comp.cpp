// =====================================================================================
//
//       Filename:  comp.cpp
//
//    Description:  http://www.hackerearth.com/tcetcyphers-2/algorithm/composite-numbers-having-7/
//
//        Version:  1.0
//        Created:  Thursday 18 September 2014 10:03:31  IST
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
#define MAX 1000010

int sieve[MAX];
bool isLucky(int a){
    while(a > 0){
        if(a % 10 == 7){
            return true;
        }
        a /= 10;
    }
    return false;
}

void preprocess(){
    REP(i, MAX){
        sieve[i] = 0;
    }
    for(LL i = 2; i < MAX; i++){
        if(!sieve[i]){
            for(LL j = i * i ; j < MAX; j += i){
                sieve[j] = 1;
            }
        }
    }

    FOR(i, 1, MAX){
        if(sieve[i]){
            sieve[i] = isLucky(i);
        }
        sieve[i] += sieve[i-1];
    }
}
int
main ( int argc, char *argv[] ){
    preprocess();
    int t;
    s(t);
    while(t--){
        int m,n;
        s(m);
        s(n);
        int cnt = sieve[n] - sieve[m - 1];
        if(!cnt){
            cnt = -1;
        }
        printf("%d\n", cnt);
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

