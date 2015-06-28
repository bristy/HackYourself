// =====================================================================================
//
//       Filename:  strongstring.cpp
//
//    Description:  http://www.hackerearth.com/gsf-hacks/algorithm/the-strongest-string-1-1/
//
//        Version:  1.0
//        Created:  Friday 11 April 2014 09:31:06  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================

#include	<stdlib.h>
#include    <iostream>
#include    <string>
using namespace std;
#define EXIT_SUCCESS 0

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================
    int
main ( int argc, char *argv[] )
{
    int n, largest = -1;
    string str;
    cin>>n>>str;

    int cnt[256] = {0};
    string ret = "";
    for(int i = 0; i<n; i++){
        int c = str[i] - 'a';
        if(cnt[c] == 0){
            cnt[c] = 1;
            ret += str[i];
            if(largest < c){
                largest = c;
            }
        }
    }
    n = ret.length();
    for(int i = 0; i<n; i++){
        int c  = ret[i] - 'a';
        if(c == largest){
            ret = ret.substr(i, n-i);
            break;
        }
    }
    cout<<ret;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
