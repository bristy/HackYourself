#include <iostream>
#include <string>
using namespace std;


int main(){
    int t;
    cin>>t;
    string in;
    while(t--){
        cin>>in;
        int cnt = 0;
        int len = 0;
        bool increase = true;

        int to = in.length();
        int prev = 0;
        for(int i =0; i<to; i++){
            if(in[i] == '<'){
                cnt++;
                if(increase)len++;
            } else {
                if(cnt > 0){
                    if(increase)len++;
                    cnt--;
                }else {
                    increase = false;
                }
            }
            if(cnt == 0){
                prev = len;
            }

        }

        cout<<prev<<endl;
    }

    return 0;
}
