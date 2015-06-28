#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define MAX 200010
int main() {
    int n, l, m;
    set<int> mypq;
    cin>>n>>l>>m;
    int ways = 0;
    int data[MAX];
    for(int i = 0; i < n; i++) {
        cin>>data[i];
    }

    for(int i = 0; i<m - 1; i++) {
        mypq.insert(data[i]);
    }
    for(int i = m - 1; i < n; i++) {
        mypq.insert(data[i]);
        int melm = *mypq.rbegin();
        if(melm <= l) {
            ways++;
        }
        mypq.erase(data[i + 1 - m]);

    }
    cout<<ways<<"\n";

}
