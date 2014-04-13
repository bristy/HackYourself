// =====================================================================================
//
//       Filename:  tangdiv.cpp
//
//    Description:  http://www.codechef.com/APRIL14/problems/TANGDIV
//
//        Version:  1.0
//        Created:  Thursday 10 April 2014 10:30:55  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================


#include	<cstdlib>
#include    <iostream>
#include    <cstdio>
using namespace std;

#define EXIT_SUCCESS 0
#define MAX 510
typedef pair<int, int> PII;

PII chef[MAX], boy[MAX];
// ===  FUNCTION  ======================================================================
//         Name:  isIn
//  Description:  
// =====================================================================================
    bool
isIn (PII a, PII b, int n )
{
    int p,q,r,s;
    p = a.first;
    q = a.second;
    r = b.first ;
    s = b.second;
    if(p>q){
        q = q+n;
    }
    if(r>s){
        s = s+n;
    }


    return (p>=r && q<=s);
}		// -----  end of function isIn  -----
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================
    int
main ( int argc, char *argv[] )
{
    int t;
    scanf("%d",&t);
    int n, k, p;
    while(t--){
        scanf("%d%d%d", &n,&k,&p);
        int aa, bb;
        for(int i = 0; i<k;i++){
            scanf("%d%d", &aa, &bb);
            chef[i] = make_pair(aa-1, bb-1);
        }
        for(int i =0; i<p; i++){
            scanf("%d%d", &aa, &bb);
            boy[i] = make_pair(aa-1, bb-1); 
        }

        bool ret = true;
        for(int i =0; i<k&&ret; i++){
            int ok = false;
            for(int j = 0; j<p; j++){
                if(isIn(chef[i], boy[j], n)){
                    ok = true;
                }
            }
            if(!ok){
                ret = false;
            }
        }

        if(ret){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
