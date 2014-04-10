// =====================================================================================
//
//       Filename:  bintree.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  Thursday 10 April 2014 12:04:05  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================


#include	<iostream>
using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  parent
//  Description:  
// =====================================================================================
    int
parent ( int node )
{
    return node>>1;
}		// -----  end of function parent  -----
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================
    int
main ( int argc, char *argv[] )
{
    int n;
    int i,j;
    cin>>n;
    while(n--){
        cin>>i>>j;
        int ret = 0;
        while(i != j){
            if(i>j){
                i = parent(i);
                ret++;
            } else{
                ret++;
                j = parent(j);
            }
            
        }
        cout<<ret<<endl;
    }
    return 0;
}				// ----------  end of function main  ----------
