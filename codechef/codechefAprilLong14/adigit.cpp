// =====================================================================================
//
//       Filename:  adigit.cpp
//
//    Description:  http://www.codechef.com/APRIL14/problems/ADIGIT
//
//        Version:  1.0
//        Created:  Thursday 10 April 2014 12:58:47  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================

#include	<iostream>
#include    <string>
#include    <cstdlib>
using namespace std;

#define MAX_N 100010
#define MAX_A 10
#define EXIT_SUCCESS 0
int num[MAX_N]; //index 1
int count[MAX_N][MAX_A];

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================
    int
main ( int argc, char *argv[] )
{
    int n,m;
    string str;
    cin>>n>>m>>str;
    for(int i = 1; i<=n; i++){
        num[i] = str[i-1] - '0';
    }
    // preprocessing
    for(int i=0; i<MAX_A; i++){
        count[0][i] = 0;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<MAX_A; j++){
            if(j == num[i]){
                count[i][j] = count[i-1][j]+1;
            } else {
                count[i][j] = count[i-1][j];
            }
        }
    }
    int idx;
    for(int i = 0; i<m; i++){
        int ret = 0;
        cin>>idx;
        int val = num[idx];
        for(int j = 0; j<MAX_A; j++){
           int cnt = count[idx-1][j];
          if(j<=val){
            ret = ret + cnt*(val - j);
          } else {
            ret = ret + cnt*(j - val);
          }
        
        }
        cout<< ret<<endl;
    }
    
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
