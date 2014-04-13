// =====================================================================================
//
//       Filename:  magictrick.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  Saturday 12 April 2014 11:29:14  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================

#include	<stdlib.h>
#include    <iostream>
#define MAX_N 10
#define EXIT_SUCCESS 0
using namespace std;

int grid1[MAX_N][MAX_N];
int grid2[MAX_N][MAX_N];
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================
    int
main ( int argc, char *argv[] )
{
    int t; 
    cin>>t;
    int n =4;
    int n1, n2;
    int zz = 1;
    while(t--){
        cin>>n1;
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>grid1[i][j];
            }
        }
        cin>>n2;
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>grid2[i][j];
            }
        }

        int cnt[MAX_N*MAX_N+1] = {0};
        for(int i = 0; i<n; i++){
            cnt[grid1[n1-1][i]]++;
        }
        int cnt_num = 0;
        int num = -1;
        for(int i = 0; i<n; i++){
            if(cnt[grid2[n2-1][i]] > 0){
                cnt_num++;
                num = grid2[n2-1][i];
            }
        }
        cout<<"Case #"<<zz<<": ";
        zz++;
        if(cnt_num == 1){
            cout<<num<<endl;
        } else if(cnt_num == 0){
            cout<<"Volunteer cheated!\n";
        } else {
            cout<<"Bad magician!\n";
        }
    }
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
