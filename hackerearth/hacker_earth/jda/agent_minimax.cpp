// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#define N 1000000
#define INF -1e9
using namespace std;

int matrix [100 + 2] [100 + 2];
int path [100 + 2][100 + 2];
int first = 0;
void print_path(int i, int j){
    if(i != j){
        print_path(i, path[i][j]);
    }
    if(first){
        cout<<" ";
    }
    first = 1;
    cout<<j;
}

int main (){
    int n;
    int r;

    scanf ("%d %d", &n, &r) ;
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ){
            matrix [i] [j] = INF;
            path[i][j] = i;
        }
        matrix [i] [i] = 0;
    }
    for ( int i = 0; i < r; i++ ) {
        int c1;
        int c2;
        int p;

        scanf ("%d %d %d", &c1, &c2, &p);

        matrix [c1] [c2] = matrix [c2] [c1] = p - 1;
    }

    int source;
    int destination;
    int tourist;

    scanf ("%d %d %d", &source, &destination, &tourist);

    for ( int k = 1; k <= n; k++ ) {
        for ( int i = 1; i <= n; i++ ) {
            if ( matrix [i] [k] != INF ) {
                for ( int j = 1; j <= n; j++ ) {
                    if ( matrix [k] [j] != INF && i != j ){
                        int temp = min(matrix[i][k], matrix[k][j]);
                        if(temp > matrix[i][j]){
                            matrix[i][j] = temp;
                            path[i][j] = path[k][j];
                        }
                    }
                }
            }
        }
    }

    print_path(source, destination);
    cout<<endl;
    if ( source == destination ) {
        printf ("1");

    } else {
        //cout<<matrix[source][destination]<<"    tourist  "<<tourist<<endl;
        int trip = tourist / matrix [source][destination];
        if ( trip * matrix[source][destination] < tourist )
            trip++;

        printf ("%d", trip);
    }
    return 0;
}

// @END_OF_SOURCE_CODE
