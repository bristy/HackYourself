// =====================================================================================
//
//       Filename:  black_box.cpp
//
//    Description:  http://www.hackerearth.com/superprofs-hiring-challenge/algorithm/blackbox-2-8/
//
//        Version:  1.0
//        Created:  Saturday 11 October 2014 09:18:58  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================

#include<iostream>
#include <cstdio>
using namespace std;

int ret[1001];

void preprocess(){
    int n = 1001;
    int temp=0;
	int ans[10000]={1};
	int m=1,p=1;
	ret[1] = 1;
    for(int i=2; i<=n;i++){
		for(int j=0;j<m;j++){
			p=i*ans[j]+temp;
			ans[j]=p%10;
			temp=p/10;
		}
		while(temp){
			ans[m]=temp%10;
			temp/=10;
			m++;
		}
        for(int x = 0; x < m; x++){
            ret[i] += ans[x];
        }
	}

}
int main(){
    preprocess();
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
	    scanf("%d", &n);
		printf("%d\n", ret[n]);
	    
	}
	return 0;
}


