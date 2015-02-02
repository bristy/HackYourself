#include<iostream>
#include <cstdio>
using namespace std;

#define MAX 1048577 // 1<<20 + 1
int d, idx;
int last;
int getLeaf(int root, int balls){
    int ll = root << 1;
    int rr = ll + 1;
    if(ll <= last && rr <= last){
        if(balls&1){
            return getLeaf(ll, balls/2 + 1);
        }else{
            return getLeaf(rr, balls / 2);
        }
    } else{
        return root;
    }

}
void solve(){
    scanf("%d%d", &d, &idx);
    last = 1 << d;
    printf("%d\n", getLeaf(1, idx));
   
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    scanf("%d", &t);
}
