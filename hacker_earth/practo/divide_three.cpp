#include <bits/stdc++.h>
#define lli long long
#define pll pair <lli, lli>
using namespace std;
inline void fi(int *a){
 register char c=0;
 while (c<33) c=getchar_unlocked();
 *a=0;
 int tmp = 0;
 while (c>33){
     if ( c == 45 ) tmp = 1;
     else *a=*a*10+c-'0';
     c=getchar_unlocked();
 }
 if ( tmp == 1 ) *a = 0-(*a);
}
inline void fii(long long *a){
 register char c=0;
 while (c<33) c=getchar_unlocked();
 *a=0;
 int tmp = 0;
 while (c>33){
     if ( c == 45 ) tmp = 1;
     else *a=*a*10+c-'0';
     c=getchar_unlocked();
 }
 if ( tmp == 1 ) *a = 0-(*a);
}
// balanced parition algo starts
pll func(lli A[], int n)
{
	
    int Lsz = 1 << n/2;    // size of sumL
    int Rsz = 1 << (n - n/2);    //size of sumR
    
	lli sumL[Lsz+2],sumR[Rsz+2],totalSum = 0,temp,sum;
	
    for( int i = 0 ; i < Lsz ; i++){
            temp = 0;
            for( int j = 0 ; j < n/2 ; j++){
                    if( (i & (1 << j)) > 0 )
                            temp +=  A[j];
            }
            sumL[i] = temp;
    }
    
    for(int i = 0 ; i < Rsz ; i++) {
    		temp = 0;
            for(int j = 0 ; j < n-n/2 ; j++){
                    if( (i&(1<<j)) > 0 )
                            temp += A[j + n/2];
            }
            sumR[i] = temp;
    }
    
    sort( sumL , sumL+Lsz );
    sort( sumR , sumR+Rsz );
    
    for(int i = 0 ; i < n ; i++) totalSum += A[i];
    lli cur = LLONG_MIN;
    int PL=0,PR=Rsz-1;
    while(PL < Lsz && PR >= 0){
            if(2LL*(sumL[PL]+sumR[PR]) <= totalSum ){
                    cur = max( cur , sumL[PL]+sumR[PR]);
                    PL++;
            }
            else PR--;
    }
	return make_pair(cur,totalSum-cur);
}
// balanced partitioning ends
// The complexity of algorithm iS slightly much more than the expected complexity.
// So, this solution is little slower. 	
int main()
{
	int t,n;
	lli fs,sc,th,P[22];
	fi(&n);
	for ( int i = 0; i < n; i++ ) fii(&P[i]);
	bool st = false;
	for ( int i = 0; i < (1<<n); i++ ) {
		if ( __builtin_popcount(i) > n/3 ) continue;
		int num = 0;
		lli sum = 0, pp[22];
		for ( int j = 0; j < n; j++ ) {
			if ( i&(1<<j) ) sum = sum + P[j];
			else pp[num++] = P[j];
		}
		pll pp1 = func(pp,num);
		lli tt[] = {sum, pp1.first, pp1.second};
		if ( (!st) || ((max(tt[0], max(tt[1], tt[2])) - min(tt[0], min(tt[1], tt[2]))) < th-fs) ) {
			sort(tt,tt+3);
			fs = tt[0];
			sc = tt[1];
			th = tt[2];
			st = true;
		}
	}
    lli mx = max(fs, max(sc, th));
	printf("%lld\n", mx);
	return 0;
}
