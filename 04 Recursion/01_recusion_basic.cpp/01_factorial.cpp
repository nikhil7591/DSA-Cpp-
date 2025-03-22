#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// factorial of number

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*factorial(n-1);
}


int main(){
    int n;
    cin>>n;

    int ans = factorial(n);
    cout<<ans<<endl;
    cout<<endl;
    return 0;
}