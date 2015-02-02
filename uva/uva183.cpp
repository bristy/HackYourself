#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 210
string ret;
int grid[MAX][MAX];
int row, col;
/**
 * return 1 if all elements are 1
 * return 0 if all elements are 0
 * return -1 else
 */
int getStatus(int tx, int ty, int bx, int by){
    int one = 0;
    int zero = 0;
    for(int x = tx; x <= bx; x++){
        for(int y = ty; y <= by; y++){
            if(grid[x][y] == 0){
                zero++;
            } else if(grid[x][y] == 1){
                one++;
            }
            if(one && zero){
                return -1;
            }
        }
    }
    if(one && zero){
        return -1;
    } else if(one){
        return 0;
    } else {
        return 1;
    }
}

void BtoD(int tx, int ty, int bx, int by){
   
    if(tx > bx || ty > by){
        return;
    }

    if(tx < 0 || tx >= row || ty < 0 || ty >= col){
        return;
    }
    int status = getStatus(tx, ty, bx, by);
    if(status == 0){
        ret += "0";
        return;
    } else if(status == 1){
        ret += "1";
        return;
    } else {
        // divide in 4 parts
        int xdis = (bx - tx) / 2;
        int ydis = (by - ty) / 2;
        // top left
        BtoD(tx, ty, tx + xdis, ty + ydis);
        if(by - ty > 0){
            // top right
            BtoD(tx, ty + ydis + 1, tx + xdis, by);
        }
        if(bx - tx > 0){
            // bottom left
            BtoD(tx + xdis, ty, bx, ty + ydis);
        }
        if(by - ty > 0 && bx - tx > 0){
            // bottom right
            BtoD(tx + xdis + 1, ty + ydis + 1, bx, by);
        }
    }
}

void solve(){
    string type;
    string line;
    while(true){
        cin>>type;
        if(type[0] == '#'){
            break;
        }

        ret = "";
        cin>>row>>col;
        cin>>line;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int idx = i * row + j;
                grid[i][j] = line[idx] - '0';
            }
        }
        BtoD(0, 0, row - 1, col - 1);
        cout<<ret;
    }
}

int main(){
    solve();
    return 0;    
}
