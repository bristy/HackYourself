// =====================================================================================
//
//       Filename:  PON.cpp
//
//    Description:  http://www.spoj.com/problems/PON/
//    trying to solve using "Fetmat Primality Test"
//
//        Version:  1.0
//        Created:  Sunday 12 October 2014 01:22:44  IST
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
#define ITER 2

/* This function calculates a*b % c */
LL mulmod(LL a, LL b, LL c){
    LL x = 0, y = a %c;
    while(b > 0){
        if(b & 1){ // b is odd
            x = (x + y) % c;
        }
        y = (y * 2) % c;
        b >>= 1;
    }
    return x % c;
}

/* This function calculates a^b % c */

LL modulo(LL a, LL b, LL c){
    LL x = 1, y = a % c;
    
    while(b > 0){
        if(b & 1){ // b is odd
            x = mulmod(x, y, c);
        }
        y = mulmod(y, y, c);
        b >>= 1;
    }
    return x % c;
}

/* this function checks if p is prime  */
bool Fermat(LL p, int iter){
    if(p == 1){ // 1 is not prime
        return false;
    }
    REP(i, iter){
        LL a = rand() % (p - 1) + 1;
        if(modulo(a, p - 1, p) != 1){
            return false; // p is definetely composite
        }
    }
    return true; // p is probabily prime
}
int
main ( int argc, char *argv[] ){
    int t;
    s(t);
    while(t--){
        LL n;
        sl(n);
        if(Fermat(n, ITER)){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

