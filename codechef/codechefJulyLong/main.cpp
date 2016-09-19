#include <cstdlib>
#include <vector>
#include<iostream>
#include<list>
#include<cstring>
#include <stdio.h>
#define mod 1000000007
using namespace std;
list<int> temp;
int dfs(int current,int visited[],int v[],int count);
long long gcd(long long a,long long b);


int primes[] = { 2,    3,      5,      7,     11,     13,     17,     19,     23,     29, 31,
    37,     41,     43,     47,     53,     59,     61,     67,     71, 
                  73,     79,     83,     89,     97,    101,    103,    107,    109,    113,
                      127,    131,    137,    139,    149,    151,    157,    163,    167,    173, 
                          179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
                              233,    239,    241,    251,    257,    263,    269,    271,    277,    281,
                                  283,    293,    307,    311,    313,    317};


/*  This function calculates (abstract)%c */
int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
        while(b > 0){
            if(b%2 == 1){
                x=(x*y)%c;
            }
            y = (y*y)%c; // squaring the base
            b /= 2;
        }
        return x%c;
}



long long lcms(vector<int> numbers){
    int best[100010] = {0};

    for(int i = 0; i<int(numbers.size()); i++){
        int num = numbers[i];
        for(int j = 0; j<66; j++){
            int cnt = 0;
            while(num % primes[j] == 0){
                cnt++;
                num /= primes[j];
            }
            best[primes[j]] = max(best[primes[j]], cnt);
        }
        if(num > 1){
            best[num] = max(best[num], 1);
        }
    }
    
    long long ret = 1;
    for(int i = 1; i<100001; i++){
        ret = (ret * modulo(i, best[i], mod))%mod;
    }

    return ret;

}
int main() {
//    freopen("test.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int v[n];
        int visited[n];
        for(int i=0;i<n;i++)
            visited[i]=0;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            v[i]=k-1;
        }
        vector<int> countParent;
        for(int i=0;i<n;i++){
            visited[i]=1;
            if(!visited[v[i]]){
//                cout<<"i is:"<<i<<"\n";
                dfs(v[i],visited,v,1);
                countParent.push_back(temp.front());
//                cout<<"temp is:"<<temp.front()<<endl;
//                for(list<int> :: iterator it=temp.begin();it!=temp.end();it++)
//                {
//                    cout<<"list elements are:"<<*it<<" ";
//                }
//                cout<<"\n";
                temp.clear();
            }else if(i==v[i]){
                countParent.push_back(1);
            }
            
        }
//        cout<<countParent.size()<<"\n";
//        for(vector<int> ::iterator it=countParent.begin();it!=countParent.end();it++)
//            cout<<"map"<<*it<<"\n";
        /*if(countParent.size()==1){  
            cout<<countParent[0]<<"\n";
            continue;
        }
        
        long long lcm;
        lcm=(1ll*countParent[0]*countParent[1]/gcd(countParent[0],countParent[1]))%mod;
        for(int i=2;i<(int)countParent.size();i++)
            lcm=(lcm*countParent[i]/gcd(lcm,countParent[i]))%mod;*/
        cout<<lcms(countParent)<<"\n";
    }
    return 0;
}

int dfs(int current,int visited[],int v[],int count){
    visited[current]=1;
//    cout<<"current is:"<<current<<"\n";
    count++;
//    cout<<"adjacent is here:"<<v[current]<<"\n";
//    cout<<"check visited:"<<visited[v[current]]<<"\n";
    if(!visited[v[current]]){
        dfs(v[current],visited,v,count);
    }
//    cout<<"count is :"<<count<<"\n";
    temp.push_back(count);
    return count;
}



long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
