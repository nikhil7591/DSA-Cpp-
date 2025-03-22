#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int binarySearch(int arr[],int s,int e,int k){
    if(s>e){
        return -1;
    }
    int mid = s+(e-s)/2;
    if(arr[mid]==k){
        return mid;
    }

    if(arr[mid]>k){
        binarySearch(arr,s,mid-1,k);
    }
    else{
        binarySearch(arr,mid+1,e,k);
    }
}

int main(){

    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int ans = binarySearch(arr,0,n-1,k);
    cout<<" Element in index "<<ans<<endl;
    return 0;
}