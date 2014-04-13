// =====================================================================================
//
//       Filename:  cnpiim.cpp
//
//    Description:  http://www.codechef.com/APRIL14/problems/CNPIIM
//
//        Version:  1.0
//        Created:  Thursday 10 April 2014 01:38:23  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================

#include	<iostream>
#include    <cstdio>
using namespace std;

#define EXIT_SUCCESS 0
typedef long long ll;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================
    int
main ( int argc, char *argv[] )
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        ll ret = 0;
        for(int i = 1; i<n; i++){
            int mul = i*(n-i);
            for(int j=1; j*j<=mul; j++){
                int d = mul/j;
                if(mul%j == 0){
                    d -= 1;
                }
                d = d-j+1;
                int ans = d*2-1;

               if(ans>0){
                    ret += ans;
               }
                //printf("%d:i %d:(n-i) %d:j  %d:d  %d:mul %d:ans\n",i,(n-i),j,d,mul, ans);
            }
        }
        printf("%lld\n", ret);
    }
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
