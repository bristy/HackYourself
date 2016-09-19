// =====================================================================================
//
//       Filename:  potatoes.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  Thursday 10 April 2014 11:30:54  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================
#include	<iostream>
#include	<stdlib.h>
using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================

// ===  FUNCTION  ======================================================================
//         Name:  isPrime
//  Description:  
// =====================================================================================
	bool
isPrime ( int n )
{
	bool ret =  1;
	if(n%2 == 0){
		ret = 0;
	} else {
		for(int i = 3; i*i<=n; i+=2){
			if(n%i == 0){
				ret = 0;
				break;
			}
		}
	}
	return ret;
}		// -----  end of function isPrime  -----
	int
main ( int argc, char *argv[] )
{ 
	int t;
	cin>>t;
	int x, y;
	while(t--){
		cin>>x>>y;
		for(int i = 1; ; i++){
			if(isPrime(x+y+i)){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}				// ----------  end of function main  ----------
