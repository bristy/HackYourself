#include <iostream>
#include <cstdio>
#include <map>
#define MAX 101
#define INF 1e9
using namespace std;

int n, m;
int grid[MAX][MAX];
map<string, int> mapping;


void solve(){
    cin>>n>>m;
    string temp;
    for(int i = 0; i < n; i++){
        cin>>temp;
        mapping[temp] = i;
    }

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            grid[i][j] = INF;
        }
    }

    string to, from;
    int dist;
    int t, f;
    for(int i = 0; i < m; i++){
        cin>>to>>from>>dist;
        t = mapping[to];
        f = mapping[from];
        grid[t][f] = grid[f][t] = dist;
    }

    // flyod warshal
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][k] + grid[k][j] < grid[i][j]){
                    grid[i][j] = grid[i][k] + grid[k][j];
                }
            }
        }
    }

    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>to>>from;
        t = mapping[to];
        f = mapping[from];
        printf("%d\n", grid[t][f]);
    }

}
int main(){
   solve(); 
}
