// =====================================================================================
//
//       Filename:  binosum.cpp
//
//    Description:  http://www.hackerearth.com/gsf-hacks/algorithm/bino-sum-1/
//
//        Version:  1.0
//        Created:  Friday 11 April 2014 09:04:02  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================


#include	<stdlib.h>
#include    <iostream>
using namespace std;
#define MOD 1000000007
#define EXIT_SUCCESS 0
#define MAX_N 1010
long long C[MAX_N][MAX_N];
// ===  FUNCTION  ======================================================================
//         Name:  calbino
//  Description:  
// =====================================================================================
    void
calbino ( )
{
    
    for(int i =0 ; i<MAX_N; i++){
        C[i][0] = 1;
    }
    for(int i = 1; i<MAX_N; i++){
        for(int j = 1; j<=i; j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
        }
    }
    return;
}		// -----  end of function calbino  -----



// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================
    int
main ( int argc, char *argv[] )
{
    calbino();

    int t, n, p;
    cin>>t;
    while(t--){
        cin>>n>>p;
        long long ret = 0;
        for(int i =0; i<=p; i++){
            ret = (ret + C[n][i])%MOD;
        }
        cout<<ret<<endl;

    }
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
