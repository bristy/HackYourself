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
#define gcd __gcd
#define maX(a,b) (a>b?a:b)
#define miN(a,b) (a<b?a:b)
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) lower_bound(all(arr),ind)-arr.begin())
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;
/*Main Code*/
#define MAX 200000
#define MOD 1000000007
#define MAX_D 11
struct node{
    int count;
};

LL values[MAX];
node T[MAX_D][MAX]; // segment tree for each count

int distinctDigit(int n){
    int C[10] = {0};
    while(n > 0){
        C[n%10]++;
        n /= 10;
    }
    int cnt = 0;
    REP(i, 10){
        cnt += C[i] > 0;
    }
    return cnt;
}
node combine(node l, node r){
	node ret;
    ret.count = l.count + r.count;
	return ret;
}

/*
void init(int k, int lo, int hi){
	if(lo==hi){
		int val = values[lo];
        int d = distinctDigit(val);
        T[d][k].count = 1;
		return;
	}
	int mid=(lo+hi)>>1;
	int next=k<<1;
	init(next,lo,mid);
	init(next+1, mid+1, hi);
	T[k]=combine(T[next], T[next+1]);
	return ;
}
*/
void updt(int k, int lo, int hi, int pos, int val, int count){
	if(lo==hi){
		T[count][k].count += val;
		return;
	}

    int mid=(lo+hi)>>1;
	int next=k<<1;
	if(pos <= mid){
        updt(next, lo, mid, pos, val, count);
    } else{ 
        updt(next+1, mid+1, hi, pos, val, count);
    }
	T[count][k] = combine(T[count][next],T[count][next+1]);
	return ;

}
node query(int k, int lo, int hi, int qlo,int qhi, int count){
	if(lo==qlo && hi==qhi){
        return T[count][k];
    }
	int mid = (lo+hi)>>1;
	int next = k<<1;
	if(mid >= qhi) return query(next, lo, mid, qlo, qhi, count);
	if(mid < qlo) return query(next+1, mid+1, hi, qlo, qhi, count);
	return combine(
		query(next, lo, mid, qlo, mid, count),
		query(next+1, mid+1, hi, mid+1, qhi, count)
		);
}
int main(){
	//freopen("in.txt","r",stdin);
	int n;
	s(n);
    REP(i, n){
        sl(values[i]);
        int d = distinctDigit(values[i]);
        updt(1, 0, n-1, i, 1, d);
    }
	int m;
	s(m);
	int ql,qh;
    int cmd;
    int x1, x;
	REP(i,m){
        cin>>cmd>>ql>>qh;
        if(cmd == 0){
            x = distinctDigit(values[ql-1]);
            values[ql-1] += qh;
            x1 = distinctDigit(values[ql-1]);
            if(x1 != x){
                updt(1, 0, n-1, ql-1, -1, x);
                updt(1, 0, n-1, ql-1, 1, x1);
            }
        } else if (cmd == 1){
            x = distinctDigit(values[ql-1]);
            values[ql-1] = qh;
            x1 = distinctDigit(values[ql-1]);
            if(x1 != x){
                updt(1, 0, n-1, ql-1, -1, x);
                updt(1, 0, n-1, ql-1, 1, x1);
            }

        } else {
            int c;
            cin>>c;
            int ans = 0;
            if(c >=0 && c<=10){
                node ret = query(1, 0, n-1, ql-1, qh-1, c);
                ans = ret.count;
            }
            cout<<ans<<endl;

        }
	}
	return 0;
}
