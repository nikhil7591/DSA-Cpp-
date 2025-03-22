#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void merge(vector<int> & arr, int s, int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int k = s; // k is main Array Index
    for(int i = 0 ;i<len1;i++){
        first[i] = arr[k++];
    }
    k = mid+1;
    for(int i = 0 ;i<len2;i++){
        second[i] = arr[k++];
    }

    // merge 
    int index1 = 0;
    int index2 = 0;
    k = s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
        }
    }
    while(index1<len1){
        arr[k++] = first[index1++];
    }
    while(index2<len2){
        arr[k++] = second[index2++];
    }
    delete []first;
    delete []second;
}

void mergeSorted(vector<int> & arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = s+(e-s)/2;
    // left part
    mergeSorted(arr,s,mid);
    // right part
    mergeSorted(arr,mid+1,e);

    // merge kardo
    merge(arr,s,e);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    int s =0;
    int e = n-1;

    mergeSorted(arr,s,e);
}




int main(){
    vector<int> arr = {1,5,3,2,4};
    int n = arr.size();

    mergeSort(arr,n);

    for(int i:arr){
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}