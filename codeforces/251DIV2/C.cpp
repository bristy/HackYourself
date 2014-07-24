// =====================================================================================
//
//       Filename:  C.cpp
//
//    Description:  http://codeforces.com/contest/439/problem/C
//
//        Version:  1.0
//        Created:  Wednesday 04 June 2014 09:29:44  IST
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
	int
main ( int argc, char *argv[] ){
    int n, k, p;
    cin>>n>>k>>p;
    VI odd;
    VI even;
    int temp;
    REP(i, n){
        cin>>temp;
        if(temp & 1){
            odd.pb(temp);
        } else {
            even.pb(temp);
        }
    }

    string ans;
    int remainOdd = sz(odd) - k +p;
    // number of odds are not enough or rest odds are odd in number
    if(sz(odd) < k-p || (sz(odd) - k + p )&1){
        cout<<"NO\n";
    } else if(sz(even) + remainOdd/2< p ){
        cout<<"NO\n";
    } else if(sz(even) >= p){
        cout<<"YES\n";
        REP(i, p-1){
            cout<<"1 "<<even[i]<<endl;
        }

        int rest = remainOdd + sz(even) - p +1;
        cout<<rest;
        for(int i = p-1; i<sz(even); i++){
            cout<<" "<<even[i];
        }

        for(int i = k-p; i<sz(odd); i++){
            cout<<" "<<odd[i];
        }
        cout<<"\n";
        for(int i = 0; i<k-p; i++){
            cout<<"1 "<<odd[i]<<endl;
        }
    } else {
        cout<<"NO\n";
        for(int i =0; i<k-p; i++){
            cout<<"1 "<<odd[i]<<endl;
        }
        REP(i, sz(even)){
            cout<<"1 "<<even[i]<<endl;
        }

        int required = p - sz(even);
        int go = 0;
        int index = k-p;
        for(; go<required-1; go++,index+=2  ){
            cout<<"2 "<<odd[index]<<" "<<odd[index+1]<<endl;


        int rest = sz(odd) - index + 1;
        cout<<rest;
        for(; index<sz(odd); index++){
            cout<<" "<<odd[index];
        }
        }
    }
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

