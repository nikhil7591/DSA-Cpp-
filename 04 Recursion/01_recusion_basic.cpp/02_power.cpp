#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// power of 2
int power(int n){
    if(n==0)
    return 1;
    return 2*power(n-1);
}

int main(){
    int n;
    cin>>n;

    cout<<power(n)<<endl;
    cout<<endl;
    return 0;
}