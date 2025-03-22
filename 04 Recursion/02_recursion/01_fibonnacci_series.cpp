#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// fibonnacci Series
int fibonnacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonnacci(n-1)+fibonnacci(n-2);
}

int main(){

    int n;
    cin>>n;

    cout<<fibonnacci(n)<<endl;
    
    return 0;
}