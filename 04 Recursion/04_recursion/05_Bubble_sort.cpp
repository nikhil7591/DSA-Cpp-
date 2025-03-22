#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Recursion bubble sort
void sortArray(int *arr, int n){
    // base case (If one element in array it is alreay sorted )
    if(n==0||n==1){
        return;
    }
    // 1 case Solve
    for(int i =0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    // RECURSION CALL
    sortArray(arr,n-1);
}

int main(){
    //Bubble Sort

    int arr[5] = {5,6,2,1,4};
    sortArray(arr,5);
    for(int i:arr){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}