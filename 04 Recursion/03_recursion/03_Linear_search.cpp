#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int linearSearch(int arr[],int size,int k){
    if(size == 0 ){
        return 0;
    }
    
    if(arr[size]== k){
        return  size;
    }
    return linearSearch(arr,size-1,k);
}

// for bool 
bool linearSearchbool(int arr[],int size,int k){
    // 
    if(size == 0 ){
        return false;
    }
    
    if(arr[size]== k){
        return  true;
    }
   else{
        return linearSearch(arr+1,size-1,k);
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

    int index = linearSearch(arr,n,k);
    cout<< " Element in index  "<<index<<endl;

    return 0;
}