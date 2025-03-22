#include<bits/stdc++.h>
using namespace std;

/*
Sets , Unordered Sets and MultiSets

*/

void print(unordered_set<string> &s){
    for(string value : s){
        cout<<value<<endl;
    }
    
}

int main(){
    // Sets
    unordered_set<string> s;
    s.insert("abc"); // O(1)
    s.insert("zsdf");
    s.insert("bcd");

    // for find in set
    auto it = s.find("abc"); // O(1)
    if(it != s.end()){
        cout<< (*it);
    }
    print(s);
    // use erase() take a 2 value iterator and value
    if(it != s.end()){
        s.erase(it);
    }
    print(s);
    return 0;
}