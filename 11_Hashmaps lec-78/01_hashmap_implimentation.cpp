#include<bits/stdc++.h>
using namespace std;

int main(){
    //creation
    unordered_map<string,int> m;

    // insertion
    pair<string,int> p = make_pair("nikhil",1);
    m.insert(p);
    pair<string,int> p1{"love",2};
    m.insert(p1);

    return 0;
}