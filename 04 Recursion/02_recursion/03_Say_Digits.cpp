#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void sayDigits(int n,string arr[]){
    // base case
    if(n==0){
        return ;
    }
    // proccessing part
    int digit = n%10;
    n = n/10;

    // recusive call
    sayDigits(n,arr);
    
    cout<<arr[digit]<<" ";
}

int main(){

    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>>n;

    sayDigits(n,arr);    
    cout<<endl;
    return 0;
}