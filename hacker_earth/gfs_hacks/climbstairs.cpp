// =====================================================================================
//
//       Filename:  climbstairs.cpp
//
//    Description:  http://www.hackerearth.com/gsf-hacks/algorithm/climbing-stairs-1/
//
//        Version:  1.0
//        Created:  Friday 11 April 2014 09:20:51  IST
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
#define EXIT_SUCCESS 0
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================
    int
main ( int argc, char *argv[] )
{
    int a,b,n;
    cin>>a>>b>>n;
    int step = a - b;
    int days;
    if(n<= a){
        days = 1;
    }
    else if((n-a)%step == 0){
        days = (n-a)/step + 1;
    } else {
        days = n/step;
        if(n%step != 0){
            days += 1;
        }
    }
    cout<<days;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
