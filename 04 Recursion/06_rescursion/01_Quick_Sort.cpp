#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// three tyoe you are partition the array in quick sort

int partition(int arr[], int s, int e){
    // pivot element
    int pivot = arr[s];
    // count number of element less than piovt element 
    int count = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    // swap count and pivot elemnt
    int pivotIndex = s+count;
    swap(arr[pivotIndex],arr[s]);

    int i = s;
    int j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[],int s ,int e){
    // base case
    if(s>=e){
        return;
    }
    // partition
    int p = partition(arr,s,e);
    // recusion call
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){

    int arr[] = {9, 9 ,9 ,8 ,2, 3, -6 };
    int n = 7;

    quickSort(arr,0,n-1);
    for(int i = 0; i<n;i++ ){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}