#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remaningParts = isSorted(arr+1,size-1);
        return remaningParts;
    }
}

int main(){

    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    if(isSorted(arr,n)){
        cout<<" array is sorted "<<endl;
    }
    else{
        cout<<" array is not sorted "<<endl;
    }

    delete []arr;
    
    return 0;
}