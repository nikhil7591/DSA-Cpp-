#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool palidrome(string str, int i){
    int n = str.length()-1;
    if(i>n-i-1){
        return true;
    }
    if(str[i]!=str[n-i-1]){
        return false;
    }
    else{
        palidrome(str,i+1);
    }
}

int main(){
    string str;
    cin>>str;

    if(palidrome(str,0)){
        cout<<" yes "<<endl;
    }else{
        cout<<" no "<<endl;
    }
    return 0;
}