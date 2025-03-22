#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    string str = "Nikhil kumar";

    stack<char> s;
    for(int i = 0;i<str.length();i++){
        s.push(str[i]);
    }

    string ans = "";
    while(!s.empty()){
        char c = s.top();
        ans.push_back(c);
        s.pop();
    }

    cout<<" Answer is "<<ans<<endl;
    return 0;
}