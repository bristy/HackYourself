// =====================================================================================
//
//       Filename:  11001.cpp
//
//    Description:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1942
//
//        Version:  1.0
//        Created:  Sunday 28 September 2014 01:56:19  IST
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
double V, V0;
double esp = 1e-6;
double getDia(int n){
    double newV = V / n;
    double ret = 0;
    if(newV > V0){
        ret = 0.03 * sqrt(newV - V0);
    }
    return ret;
}
int
main ( int argc, char *argv[] ){
    double maxLen = 0;
    int disc = 1, maxDisc = 0;
    while(true){
        scanf("%lf%lf", &V, &V0);
        if(V == 0 && V0 == 0){
            break;
        }
        while(true){
            double newDia = getDia(disc);
            if(newDia * disc == maxLen){
                // ans is not unique
                maxDisc = 0;
                break;
            }
            if(newDia * disc > maxLen){
                maxLen = newDia * disc;
                maxDisc = disc;
            }
            if(newDia == 0){
                break;
            }
            disc++;
        }
        printf("%d\n", maxDisc);

    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

