#include <iostream>
# include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 65536
#define MAXLG 17
char A[MAXN];
struct entry {
    int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN], N, i, stp, cnt;
int cmp(struct entry a, struct entry b){
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1]) : (a.nr[0] < b.nr[0]);
}
void displayL(){
    printf("displaying L--------------\n");
    for(i = 0; i < N; i++){
        printf("L[%d].nr[0] = %d:   ", i, L[i].nr[0]);
        printf("L[%d].nr[1] = %d:   ", i, L[i].nr[1]);
        printf("L[%d].p = %d:   \n", i, L[i].p);
    }
}

void displayP(){
    printf("displaying P---------------stp = %d\n", stp);
    for(i = 0; i < N; i++){
        printf("P[%d][%d] = %d\n", stp, i, P[stp][i]);
    }
}

int lcp(int x, int y){
    int ret = 0;
    if(x == y){
        return N - x;
    }


    for(int i = stp - 1; x < N && y < N && i >= 0; i--){
        if(P[i][x] == P[i][y]){
            x += 1 << i;
            y += 1 << i;
            ret += 1 << i;
        }
    }

    return ret;
}

int lcaBrute(int x, int y){
    int cnt = 0;
    while(x < N && y < N && A[x] == A[y]){
        cnt++;
        x++;
        y++;
    }
    return cnt;
}

void buildSA(){
    for (N = strlen(A), i = 0; i < N; i ++){
            P[0][i] = A[i] - 'A';
    }
    for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1){
        for (i = 0; i < N; i ++){
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        //printf("before sorting \n");
        //displayL();

        sort(L, L + N, cmp);
        //printf("after sorting \n");
        //displayL();

        for (i = 0; i < N; i ++){
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] 
                ? P[stp][L[i - 1].p] 
                : i;
        }
        //displayP();
    }

}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", A);
        buildSA();        
        long long ret = N - L[0].p;
        for(int i = 1; i < N; i++){
            ret += (N - L[i].p - lcp(L[i - 1].p, L[i].p));
        }
        
        cout<<ret<<"\n";

    }
    return 0;
}
