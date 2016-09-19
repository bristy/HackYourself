/*
 * =====================================================================================
 *
 *       Filename:  boxes.cpp
 *
 *    Description:  http://www.hackerearth.com/capillary-hiring-challenge/algorithm/connecting-boxes-1/
 *
 *        Version:  1.0
 *        Created:  Sunday 24 August 2014 03:43:15  IST
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
#include <vector>
using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
#define MAX 1001
int visited[MAX];
int N,Q;
vector<pair<int, int> > edges;


bool conflict(pair<int, int> p){

	for(int i = 0; i<(int)edges.size(); i++){
		pair<int, int> l = edges[i];
		if(p > l){
			swap(p, l);
		}
		// check for over lapping
		// .----.(p)
		//    .-----.(l)
		bool yes = p.second > l.first && p.second < l.second;
		if(yes){
			return true;
		}
	}

	return false;
}

int
main ( int argc, char *argv[] ){
	cin>>N>>Q;
	while(Q--){
		int a, b;
		cin>>a>>b;
		if(a != b && visited[a] == 0 && visited[b] == 0){
			// always make edge a < b
			if(a > b){
				swap(a, b);
			}
			if(!conflict(make_pair(a, b))){
				cout<<"NO\n";
			} else {
				cout<<"YES\n";
				edges.push_back(make_pair(a, b));
				//edges.push_back(make_pair(b, a));
				visited[a] = visited[b] = 1;
			}
		} else {
			cout<<"NO\n";
		}
	}

	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

