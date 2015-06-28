#include<stdio.h>
#define MAX 100001
#define MOD 1000000007
int th[MAX];
int mol[MAX], mor[MAX];
int  n;

int min(int a, int b){
    
    return a<=b ? a : b; 
}

void getInput(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &th[i]);
	}
	
}

void solve(){
    getInput();
    int max=0;
    int i = 0;
    
    for(i=0; i<n; i++){
	if( th[i] >= max){
		max = th[i];
		mol[i] = 0;
	}
	else{
		mol[i] = max;
	}
    }
	
    max = 0;

    for(i=n-1; i>=0; i--){
	
        if( th[i] >= max){
		max = th[i];
		mor[i] = 0;
	}
	else{
		mor[i] = max;
	}
    }
	
    long long sumwater = 0;

    for( i=0; i<n; i++){
	if(mol[i]!=0 && mor[i]!=0){
		sumwater+= min(mol[i],mor[i]) - th[i];
		sumwater %= MOD;
	}
    }
    printf("%lld\n", sumwater);
	
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
		
	}
    
}
