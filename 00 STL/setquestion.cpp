#include<bits/stdc++.h>
using namespace std;

/* 
Given N strings, print unique strings
in lexiographical order with their frequency 
N <= 10^5
|S| <= 100000
*/
int main(){
    set<string> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        m.insert(s);
    }

    for(auto pr: m){
        cout<< pr<<" ";
    }cout<<endl;
    
    return 0;
}
