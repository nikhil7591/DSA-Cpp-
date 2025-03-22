#include<bits/stdc++.h>
using namespace std;

/*
Sets , Unordered Sets and MultiSets
you can use multiset when use priority_queue you can replace the priority_queue from multiset
*/

void print(multiset<string> &s){
    for(string value : s){
        cout<<value<<endl; 
    }
    
}

int main(){
    // Sets
    multiset<string> s;
    s.insert("abc"); // log(n)
    s.insert("zsdf");
    s.insert("abc"); // log(n)
    s.insert("bcd");
    print(s);
    // for find in multiset return first value if duplicate is present
    cout<<"Find"<<endl;
    auto it = s.find("abc"); // log(n)
    if(it != s.end()){
        cout<< (*it)<<endl;
    }
    print(s);

    // use erase() take a 2 value iterator and value
    cout<<"Erase"<<endl;
    if(it != s.end()){
        s.erase(it);
    }
    //if remove all value from nultiset you can use erase(value)
    s.erase("abc");
    print(s);
    return 0;
}