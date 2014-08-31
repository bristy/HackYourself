//http://www.geeksforgeeks.org/counting-inversions/

#include<iostream>

using namespace std;
#define MAX 200010
int temp[MAX];
long long mergeParts(int arr[], int temp[], int l, int mid, int r){
    long long inv_count = 0;
    int i = l;
    int j = mid;
    int k = l;
    while((i<=mid-1) && (j<= r)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // count inversion
            inv_count += (mid - i);
        }
    }

    // append element of left part if any
    while(i<=mid-1){
        temp[k++] = arr[i++];
    }

    while(j<=r){
        temp[k++] = arr[j++];
    }
    // copy back all elemnts to original array
    for(i = l; i<=r; i++){
        arr[i] = temp[i];
    }
    return inv_count;

}

long long _mergeSort(int arr[], int temp[], int l, int r){
    int mid;
    long long inv_count = 0;
    if(l < r){
        mid = (l + r)/2;
        // sort left part
        inv_count += _mergeSort(arr, temp, l, mid);
        // sort right part
        inv_count += _mergeSort(arr, temp, mid+1, r);

        // merge left and right part
        inv_count += mergeParts(arr, temp, l, mid+1, r);
    }
    return inv_count;
}


long long mergeSort(int arr[], int arraySize){
    return _mergeSort(arr, temp, 0, arraySize-1);
}


int main(){
    int t;
    cin>>t;
    int arr[MAX];
    int n;
    while(t--){
        cin>>n;
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }

        cout<<mergeSort(arr, n)<<"\n";
    }
}
