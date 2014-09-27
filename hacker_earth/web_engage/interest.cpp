// =====================================================================================
//
//       Filename:  interest.cpp
//
//    Description:  http://www.hackerearth.com/webengage-hiring-challenge-1/algorithm/numbers-of-interest-2-1/
//
//        Version:  1.0
//        Created:  Sunday 21 September 2014 10:17:20  IST
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
typedef unsigned long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;
typedef vector< PII > VPII;
/*Main Code*/
#define EXIT_SUCCESS 0
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
#define MAX 1000011
VI primes;
int sieve[MAX];
LL x[MAX]; //x[i] smallest prime divider of i
LL y[MAX]; // y[i] sum of all proper divisors of i (including 1)


void calX(){
    fill(sieve, 0);
    fill(x, 0);
    for(LL i = 2; i < MAX; i++){
        if(!sieve[i]){
            for(LL j = i * i; j < MAX; j += i){
                if(!x[j]){ // set all x which are factor of i
                    x[j] = i; 
                }
                sieve[j] = 1;
            }
            x[i] = i;
        } 
    }

    FOR(i, 1, MAX){
        x[i] += x[i - 1];
    }
}

void calY(){
    int limit = sqrt(MAX);
    if(limit * limit < MAX){
        limit++;
    }

    FOR(i, 2, limit + 1){
        for(int j = i + i; j < MAX; j += i){
            y[j] += i;
            if(j / i > limit && i * i != j){
                y[j] += j / i;
            }
        }
    }

    FOR(i, 2, MAX){
        y[i]++;
    }
    //REP(i, 10){
    //    printf("%d\n", y[i]);
    //}
    FOR(i, 1, MAX){
        y[i] += y[i - 1];
    }
}

int main ( int argc, char *argv[] ){
    calX();
    calY();
    int t;
    s(t);
    LL n;
    while(t--){
        sl(n);
        printf("%lld\n", (x[n] + y[n]) % n);
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

