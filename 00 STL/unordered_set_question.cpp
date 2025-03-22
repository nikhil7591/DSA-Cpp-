#include<bits/stdc++.h>
using namespace std;
/*
Given N string and Q queries
In each query you are a given a string print yes if string is present
else print no
N <=10^6
|S| <= 100
Q <= 10^6
*/
int main(){
    unordered_set<string> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        m.insert(s);
    }

    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(m.find(s) == m.end()){
            cout<<"No\n";
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
 
    return 0;
}