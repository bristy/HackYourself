// =====================================================================================
//
//       Filename:  PALIN.cpp
//
//    Description:  http://www.spoj.com/problems/PALIN/
//
//        Version:  1.0
//        Created:  Sunday 19 October 2014 02:33:12  IST
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


VI original, curr;

void work(int pos1, int pos2){
    if(pos1 < 0){
        curr[sz(curr) - 1] = 1;
        curr.insert(curr.begin(), 1);
        return;
    } else if(curr[pos1] < 9){
        curr[pos1] = curr[pos2] = curr[pos1] + 1;
        return;
    } else {
        curr[pos1] = curr[pos2] = 0;
        work(pos1 - 1, pos2 + 1);
        return;
    }
}


// return true if l is less than or equalto r
bool isLessOrEqueal(const VI &l, const VI &r){
    if(sz(l) != sz(r)){
        return sz(l) <= sz(r);
    }

    REP(i, sz(l)){
        if(l[i] !=r[i]){
            return l[i] < r[i];
        }
    }

    return true;
}

void print(){
    REP(i, sz(curr)){
        printf("%d", curr[i]);
    }
    printf("\n");
}

void mirror(){
    int l = 0;
    int r = sz(curr) - 1;
    while(l < r){
        curr[l] = curr[r] = min(curr[l], curr[r]);
        l++;
        r--;
    }
}

int
main ( int argc, char *argv[] ){
    string str;
    int t;
    s(t);
    while(t--){
        curr.clear();
        original.clear();
        cin>>str;
        REP(i, (int)str.length()){
            original.pb(str[i] - '0');
            curr.pb(str[i] - '0');
        }
        
        // mirror current
        mirror();
        // after mirror
        //printf("After mirror\n");
        //print();
        
        while(isLessOrEqueal(curr, original)){
            int n = sz(original) - 1;
            work(n/2, (n+1) / 2);
        }

        print();
                
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

