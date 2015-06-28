// =====================================================================================
//
//       Filename:  suffix_array.cpp
//
//    Description:  suffix array implementation
//
//        Version:  1.0
//        Created:  Monday 15 September 2014 01:31:04  IST
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
#define MAXN 100010
#define MAXLG 20


char A[MAXN];
struct entry {
    int nr[2];
    int p;
} L[MAXN];

int P[MAXLG][MAXN];
int N, stp, cnt;
int sa[MAXN];

int cmp(struct entry a, struct entry b){
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);

}

int lca(int x, int y){
    if(x == y){
        return N - x;
    }
    cnt = 0;
    for(int k = stp - 1; x < N && y < N && k >=0; k--){
        if(P[k][x] == P[k][y]){
            cnt += 1 << k;
            x += 1 << k;
            y += 1 << k;
        }
        k--;
    }
    return cnt;
}

int lcaBrute(int x, int y){
    int cnt = 0;
    while(x < N && y < N && A[x] == A[y]){
        cnt++;
        x++;
        y++;
    }
    return cnt;
}

void displayL(){
    printf("displaying L--------------\n");
    REP(i, N){
        printf("L[%d].nr[0] = %d:   ", i, L[i].nr[0]);
        printf("L[%d].nr[1] = %d:   ", i, L[i].nr[1]);
        printf("L[%d].p = %d:   \n", i, L[i].p);
    }
}

void displayP(){
    printf("displaying P---------------stp = %d\n", stp);
    REP(j, N){
        printf("P[%d][%d] = %d\n", stp, j, P[stp][j]);
    }
}

void buildSA(){
    N = strlen(A);
    REP(i, N){
        P[0][i] = A[i] - 'A';
    }

    for(stp = 1, cnt = 1; (cnt >> 1) < N; stp++, cnt <<= 1){
        // printf("executing stp = %d\n", stp - 1);
        REP(i, N){
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = cnt + i < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
    
        // printf("before sorting \n");
        // displayL();
        sort(L, L + N, cmp);
        REP(i, N){
            if(i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]){
                P[stp][L[i].p] = P[stp][L[i - 1].p];
            } else {
                P[stp][L[i].p] = i;
            
            }
        }
        // printf("after sorting \n");
        // displayL();
        // displayP();
    }
    REP(i, N){
        sa[i] = L[i].p;
    }
}

void solve(){
    int t; s(t);
    while(t--){
        scanf("%s", A);
        buildSA();
        LL ret = N - sa[0];
        FOR(i, 1, N){
            printf("%d %d %d\n", sa[i-1], sa[i], lca(sa[i-1], sa[i]));
            ret += (N - sa[i] - lcaBrute(sa[i - 1], sa[i]));
        }
        cout<<ret<<"\n";
    }
}

int
main ( int argc, char *argv[] ){
    solve();
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

