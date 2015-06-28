#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_N 100010
vector<int> graph[MAX_N];
int tin[MAX_N];
int tout[MAX_N];
int level[MAX_N];
int timer;
int n;
int root;

void dfs(int v, int l){
    tin[v] = timer++;
    level[v] = l;
    for(int i = 0; i<graph[v].size(); i++){
        int u = graph[v][i];
        dfs(u, l+1);
    }
    tout[v] = timer++;
}

bool isUppar(int a, int b){

    return tin[a]<tin[b] && tout[a]>tout[b];
}

void solve(){

    dfs(root, 0);
    int q;
    scanf("%d", &q);
    int a, b;
    while(q--){

        scanf("%d%d", &a,&b);

        if(!isUppar(b-1, a-1)){
            printf("-1\n");
        } else {
            printf("%d\n", (level[a-1] - level[b-1] -1));
        }

    }

}


int main(){

    int t;
    scanf("%d", &t);
    while(t--){
      scanf("%d", &n);
      for(int i = 0; i<MAX_N; i++){
        graph[i].clear();
        tin[i]= 0;
        tout[i]=0;
        level[i]=0;
      }
      int a;
      for(int i = 0; i<n; i++){
        scanf("%d", &a);
        if(a > 0){
            graph[a-1].push_back(i);
        } else {
            root = i;
        }
      }
      timer = 0;

      solve();
      //printf("\n")
    }
}
