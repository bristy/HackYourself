// =====================================================================================
//
//       Filename:  PE50.cpp
//
//    Description:  http://projecteuler.net/problem=50
//
//        Version:  1.0
//        Created:  Sunday 04 May 2014 11:19:56  IST
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


#define MAX 1000010
VI primes;
VLL primeSum;
int isPrime[MAX];
int noOfPrimes = 0;
// ===  FUNCTION  ======================================================================
//         Name:  sieve
//  Description:  
// =====================================================================================
    void
sieve ( int limit ){
    fill(isPrime, 1);
    isPrime[0] = isPrime[1] = 0;// 0 and 1 are not prime
    primeSum.pb(0);
    for(int i = 2; i<limit; i++){
        if(isPrime[i]){
            for(LL j = (LL)i*i; j<=limit; j+= i){
               isPrime[int(j)] = 0; 
            }
            primes.pb(i);
            noOfPrimes++;
        }
    }
    LL sum = 0;
    REP(i, sz(primes)){
        sum = sum + primes[i];
        primeSum.pb(sum);
    }
    return;
}		// -----  end of function sieve  -----



// ===  FUNCTION  ======================================================================
//         Name:  calSum
//  Description:  calculate sum from index i to index j
// =====================================================================================
    LL
calSum ( int i, int j  ){

    return primeSum[j+1] - primeSum[i];
}		// -----  end of function calSum  -----

// ===  FUNCTION  ======================================================================
//         Name:  solve
//  Description:  
// =====================================================================================
    void
solve (  ){
    REP(i, 10){
        printf("%lld    ", primeSum[i]);
    }
    printf("\n");
    int limit = 1000000;
    int ret = 0;
    int best = 0;
    REP(i, noOfPrimes){
        FOR(j,i+1, noOfPrimes){
            LL sum = calSum(i, j);
            if(sum>limit){
                break;
            }
            if(isPrime[sum]){
                if(j-i+1 > best){
                     best = j-i+1;
                     ret = sum;
                     printf("count: %d   :   ret: %d  i:%d   j:%d\n",best, ret,i,j );
                }
            }
        }
    }

    printf("Result is %d : ", ret);
    return ;
}		// -----  end of function solve  -----



// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] )
{
	sieve(MAX);
    solve();
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

