// =====================================================================================
//
//       Filename:  arches.cpp
//
//    Description:  http://www.hackerearth.com/tatvik-hiring-challenge/algorithm/nice-arches-1/
//
//        Version:  1.0
//        Created:  Saturday 23 August 2014 09:53:45  IST
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

bool overlap(PII a, PII b){
    if(a>b){
        swap(a, b);
    }

    return a.second > b.first && a.second < b.second;
}
bool check(string word){
    int A = 0;
    int B = 0;
    int n = word.length();

    VPII arches ;
    int lastA = -1;
    int lastB = -1;
    REP(i, n){
        if(word[i] == 'A'){
            A++;
            if(lastA == -1){
                lastA = i;
            } else {
                arches.pb(mp(lastA, i));
                lastA = -1;
            }
        } else {
            B++;
            if(lastB == -1){
                lastB = i;
            } else {
                arches.pb(mp(lastB, i));
                lastB = -1;
            }
        }
    }
    if(A%2 || B%2){
        return false;
    }

    for(int i = 1; i< arches.size(); i++){
        if(overlap(arches[i-1], arches[i])){
            return false;
        }
    }

    return true;
}

int
main ( int argc, char *argv[] ){
    int m;
    string word;
    s(m);
    int cnt = 0;
    REP(i, m){
        cin>>word;
        if(check(word)){
            cnt++;
        }

    }

    printf("%d\n", cnt);
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

