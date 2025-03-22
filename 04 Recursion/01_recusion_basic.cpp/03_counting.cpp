#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// print counting in decending order
void printDecending(int n){
    if(n==0)
    return;
    cout<<n<<endl;
    printDecending(n-1);
}
// print counting in acending order
void printAcending(int n){
    if(n==0)
    return;
    printAcending(n-1);
    cout<<n<<endl;
}


int main(){
    int n;
    cin>>n;
    printDecending(n);
    cout<<endl;

    printAcending(n);
    cout<<endl;

    return 0;
}