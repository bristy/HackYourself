// =====================================================================================
//
//       Filename:  triangular.cpp
//
//    Description: http://www.hackerearth.com/tb-andr111918/problems/e13394af29ad3ec269a8005bf9eb6db8/  
//
//        Version:  1.0
//        Created:  Sunday 16 November 2014 06:24:42  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================

#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
#define MAX 1000000000010
long long bound;
vector<long long> num;
bool comp(const long long l, const long long r){
	//cout<<l<<"  "<<r<<"   "<<bound<<"\n";
	return l+r<= bound;	
}

void preprocess(){
	long long temp = 1;
	num.push_back(temp);
	for(int i = 2; temp < MAX; i++){
		temp = temp+i;
		num.push_back(temp);
	}
}

long long count(long long b){
	bound = b;
	long long ret = 0;
	for(vector<long long> :: iterator it = num.begin(); it < num.end(); it++){
		long long cnt = lower_bound(it, num.end(), *it, comp) - (it);
		//cout<<"cnt  "<<cnt<<"\n";
		if(cnt >0){
			ret += cnt;
		}
	}
	return ret;
}
	int
main (){

	int q;
	cin>>q;
	preprocess();
	long long l, r;
	while(q--){
		cin>>l>>r;
		cout<<count(r) - count(l - 1)<<"\n";
	}
	return EXIT_SUCCESS;
}
