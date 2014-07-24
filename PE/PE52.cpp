// =====================================================================================
//
//       Filename:  PE52.cpp
//
//    Description:  http://projecteuler.net/problem=52
//
//        Version:  1.0
//        Created:  Sunday 04 May 2014 01:11:22  IST
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
//         Name:  isSame
//  Description:  check if a and b contains same digits
// =====================================================================================
    bool
isSame ( LL a, LL b ){
    int cnt[10];
    fill(cnt, 0);
    
    while(a>0){
        cnt[a%10]++;
        a/=10;
    }

    while(b>0){
        cnt[b%10]--;
        b/=10;
    }
    REP(i,10){
        if(cnt[i] != 0){
            return false;
        }
    }

    return true;
}		// -----  end of function isSame  -----




// ===  FUNCTION  ======================================================================
//         Name:  solve
//  Description:  
// =====================================================================================
    void
solve ( ){
    int nums[6];
    for(int i ; ; i++){
        FOR(j,1,7){
            nums[j-1] = i*j;
        }
        bool ok = true;
        REP(i,6){
            if(!isSame(nums[i], nums[(i+1)%6])){
                ok = false;
                break;
            }
        }

        if(ok){
            printf("%d", nums[0]);
            break;
        }

    }
    return;
}		// -----  end of function solve  -----
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] ){
    solve();
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

