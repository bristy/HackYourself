#include <iostream>
#include <cstdio>
#include <string>

#define FIVE '5'
#define THREE '3'
using namespace std;

string input;

bool isConsist(const string &s, char c){
    for(int i = 0; i < s.length(); i++){
        if(s[i] != c){
            return false;
        }
    }
    return true;
}

void print(char c, int times){
    for(int i = 0; i < times; i++){
        printf("%c", c);
    }

}

void solve(){
    int t;
    cin>>t;
    while(t--){
        cin>>input;
        int n = input.length();
        // if all is 5
        if(isConsist(input, FIVE)){
            print(THREE, n + 1);
        } else if(isConsist(input, THREE)){ // if all is 3
            print(THREE, n - 1);
            print(FIVE, 1);
        } else if (input[0] < THREE) {
            print(THREE, n);

        } else if(input[0] > FIVE){
            print(THREE, n + 1);
        } else if(input[0] == FIVE){
            int nonFive = 0;
            for(int i = 0; i < n; i++){
                if(input[i] != FIVE){
                    nonFive = i;
                    break;
                }
            }
            if(input[nonFive] > FIVE){
                print(THREE, n + 1);

            } else if(input[nonFive] < THREE){
                print(FIVE, nonFive);
                print(THREE, n - nonFive);
            } else {
                print(FIVE, nonFive +  1);
                print(THREE, n - nonFive - 1);
            }

        } else if(input[0] == '4'){
            print(FIVE, 1);
            print(THREE, n - 1);
        } else {
            int nonThree = 0;
            for(int i = 0; i < n; i++){
                if(input[i] != THREE){
                    nonThree = i;
                    break;
                }
            }
            if(input[nonThree] > FIVE){
                print(THREE, n + 1);
            }
           else if(input[nonThree] == FIVE) {
                //printf("nonthree = %d\n", nonThree);
                print(THREE, nonThree - 1);
                print(FIVE, 1);
                print(THREE, n - nonThree - 1 + 1);
            }


           
            else if(input[nonThree] < THREE){

                print(THREE, n);
            } 
            else  {
                //printf("nonthree = %d\n", nonThree);
                print(THREE, nonThree);
                print(FIVE, 1);
                print(THREE, n - nonThree - 1);
            }

        }
        printf("\n");
    }

}

int main(){
    solve();
    return 0;
}
