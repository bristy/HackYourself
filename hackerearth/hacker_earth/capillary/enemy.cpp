/*
 * =====================================================================================
 *
 *       Filename:  enemy.cpp
 *
 *    Description:  http://www.hackerearth.com/capillary-hiring-challenge/algorithm/count-enemies-5/
 *
 *        Version:  1.0
 *        Created:  Sunday 24 August 2014 02:14:21  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  

using namespace std;
#define EXIT_SUCCESS 0
// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] ){

	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		int X = 0;
		int O = 0;
		int ret = 0;
		int i = 0;
		int n = s.length();
		while(i < n){
			if(s[i] == '*'){
				if(X == 0){
					ret += O;
				}
				X = 0;
				O = 0;
			
			} else if(s[i] == 'X'){
				X++;
			} else {
				O++;
			}

			i++;
		}

		if(X == 0){
			ret += O;
		}

		cout<<ret<<"\n";
	}
	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 



