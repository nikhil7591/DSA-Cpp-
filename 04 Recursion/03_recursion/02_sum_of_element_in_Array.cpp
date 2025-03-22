#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sumOfElement(int arr[],int size){
    if(size == 0 ){
        return arr[0];
    }
    return arr[size]+sumOfElement(arr,size-1);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int sum = sumOfElement(arr,n-1);
    cout<< " Sum of all Element is "<<sum<<endl;

    return 0;
}