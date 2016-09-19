// =====================================================================================
//
//       Filename:  race_brute.cpp
//
//    Description:  http://www.hackerearth.com/multunus-hiring-challenge-1/problems/8eae9ce7eb662d37aa2d65ec0dadd843/
//
//        Version:  1.0
//        Created:  Saturday 13 September 2014 01:23:57  IST
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
#define MAX_N 100010
#define M 1000000007
int H[MAX_N];
int main ( int argc, char *argv[] ){
    int t;
    s(t);
    int n;
    while(t--){
        s(n);
        REP(i, n){
            s(H[i]);
        }

        LL best = -1;
        int idx = 0;
        REP(i, n){
            int l = i - 1;
            int r = i + 1;
            LL X = 0;
            while(l >=0){
                if(H[l] >= H[i]){
                    break;
                }
                X += 1;
                l -= 1;
            }
            
            while(r <n){
                if(H[r] >= H[i]){
                    break;
                }
                X += 1;
                r += 1;
            }
            X = X* (i + 1) % M;
            if(X >= best){
                idx = i + 1;
                best = X;
            }

        }
        cout<<idx<<endl;
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

