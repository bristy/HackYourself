// =====================================================================================
//
//       Filename:  good_bad.cpp
//
//    Description:  http://www.hackerearth.com/practo-hiring-challenge-2/problems/3732937652bc6c8c262c693eb7131e25/
//
//        Version:  1.0
//        Created:  Saturday 22 November 2014 01:13:16  IST
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

#define HOUR  24
#define MIN 60
#define SEC 60


int dpGood[HOUR][MIN][SEC];
int dpBad[HOUR][MIN][SEC];
int PN =9;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int pi = -1, pj = -1, pk = -1;


bool isGood(int i, int j, int k){
    bool yes = true;
    REP(idx, PN){
        int pp = primes[idx];
        if(i % pp == 0 && j % pp == 0 && k % pp == 0 ){
            yes = false;
            break;
        }
    }
    return yes;
}

void preprocess() {
    for (int i = HOUR - 1; i >= 0; i--) {
        for (int j = MIN - 1; j >= 0; j--) {
            for (int k = SEC - 1; k >= 0; k--) {
                int prevGood = 0;
                int prevBad = 0;
                if (pi != -1 && pj != -1 && pk != -1) {
                    prevGood = dpGood[pi][pj][pk];
                    prevBad = dpBad[pi][pj][pk];
                }

                bool good = isGood(i, j, k);
                if (good) {
                    dpGood[i][j][k] = prevGood + 1;
                    dpBad[i][j][k] = prevBad;
                } else {
                    dpBad[i][j][k] = prevBad + 1;
                    dpGood[i][j][k] = prevGood;
                }
                pi = i;
                pj = j;
               pk = k;
            }
        }
    }
}

int gcd(int a, int b){
    if(a){
        return b;
    } else if(b){
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void solve(){
    preprocess();
    int t; s(t);
    while(t--){
        int hh, mm, ss;
        scanf("%d%d%d", &hh, &mm, &ss);
        //printf("%d %d %d", hh, mm, ss);
        int good = dpGood[hh][mm][ss];
        int bad = dpBad[hh][mm][ss];
        if(good != 0 && bad != 0){
            int d = gcd(good, bad);
            good /= d;
            bad /= d;
        }
        printf("%d:%d\n", bad, good);
    }
}

int
main ( int argc, char *argv[] ){
    solve();
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

