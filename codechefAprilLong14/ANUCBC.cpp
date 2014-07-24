// =====================================================================================
//
//       Filename:  ANUCBC.cpp
//
//    Description:  http://www.codechef.com/problems/ANUCBC
//
//        Version:  1.0
//        Created:  Thursday 17 April 2014 12:01:06  IST
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

#define MAX_N 100010
#define MAX_M 110
#define MOD 1000000009

int cnt[MAX_M];
int num[MAX_N];
LL sum[MAX_M];
LL factMod[MAX_N];
LL inverseFactMod[MAX_N];
LL dp[MAX_M][MAX_M];
// ===  FUNCTION  ======================================================================
//         Name:  countPow
//  Description:  find power of p in n!
// =====================================================================================
    int
countPow ( int n, int p ){
    int k = 0;
    while(n>=p){
        k+= n/p;
        n /= p;
    }
    return k;
}		// -----  end of function countPow  -----


// ===  FUNCTION  ======================================================================
//         Name:  pow
//  Description:  calculate a^b mod c
// =====================================================================================
    LL
pow ( int a, int b, int c ){
    LL x = 1;
    LL y = a;
    while(b>0){
        if((b&1) == 1){
            x = (x*y);
            if(x>c){
                x %= c;
            }
        }
        y = y*y;
        if(y >c){
            y %= c;
        }
        b = b>>1;
    }
    return x%c;
}		// -----  end of function pow  -----


// ===  FUNCTION  ======================================================================
//         Name:  inverse
//  Description:  calclate a^-1 mod p
// =====================================================================================
    LL
inverseEuler ( int a, int p){
    return pow(a, p-2, p);
}		// -----  end of function inverse  -----


// ===  FUNCTION  ======================================================================
//         Name:  preprocess
//  Description:  
// =====================================================================================
    void
preprocess ( ){
    factMod[0] = 1;
    inverseFactMod[0] = 1;
    FOR(i,1,MAX_N){
        factMod[i] = (factMod[i-1]*i)%MOD;
        inverseFactMod[i] = inverseEuler(factMod[i], MOD);
    }
    return ;
}		// -----  end of function preprocess  -----



// ===  FUNCTION  ======================================================================
//         Name:  choose
//  Description:  C(n, r) % p
// =====================================================================================
    LL
choose ( int n, int r, int p ){
    LL ret = 0;
    if(countPow(n, p) <= countPow(r, p) + countPow(n-r, p)){
        ret = (factMod[n]*((inverseFactMod[r] * inverseFactMod[n-r])%p))%p;
    }
    return ret;
}		// -----  end of function choose  -----

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================

int
main ( int argc, char *argv[] ){

    int t;
    int n,m,q;
    int a;
    for(s(t); t; t--){
        s(n);
        s(q);
        REP(i,n){
            s(num[i]);
        }
        
        REP(z,q){
            s(m);
            fill(cnt, 0);
            REP(i,n){
                a = num[i];
                cnt[(m + a%m)%m]++;
            }
            fill(sum, 0);


            REP(i, m){
                REP(k, cnt[i]+1){
                    sum[(k*i)%m] += choose(cnt[i], k, MOD);
                    sum[(k*i)%m] %= MOD;
                }

                REP(j,m){
                    dp[i][j] = 0;
                    REP(k, m){
                        dp[i][j] = (dp[i][j] + (dp[i][j-k]*sum[k])%MOD)%MOD;
                    }
                }
            }
            printf("%lld\n", dp[m-1][0]);
        }


    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

