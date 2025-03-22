#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void reverse(string& str, int i){
    int n = str.length();
    if(i>(n-i-1)){
        return;
    }
    swap(str[i],str[n-i-1]);
    i++;

    reverse(str,i);
}

int main(){
    string str = "name";
    int i = 0;
    // int j = str.length()-1;
    reverse(str,i);
    cout<<str<<endl;
    return 0;
}