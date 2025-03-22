#include<bits/stdc++.h>
using namespace std;
/*
unordered_map:
1. inbuilt implementation -> use hash table
2. Time complexity
3. valid keys datatypes
*/
void print(unordered_map<int,string> &m){
    for(auto &pr : m){
        cout<< pr.first <<" "<<pr.second<<endl;
    }
    cout<<"Size of map "<<m.size()<<endl;
}

int main(){

    unordered_map<int,string> m;
    m[1] = "anss"; // tc O(1) average time complexity

    m[3] = "anss";
    m[5] = "anss";
    m[6]; // ager tum m[6] be likh doge na tabbi hamri tc O(1) ho jaygi
    // one more option to store the data 
    m.insert({0,"dhd"});

    print(m);
    // to find any key in map
    auto it = m.find(3); // TC O(1)

    if(it == m.end()){
        cout<<"No value"<<endl;
    }else{
        cout<< it->first <<" " <<it->second<<endl;
    }

    // to erase or delete the key from map
    cout<<"After erase "<<endl;
    m.erase(5); // TC O(1)
    // in erase you can enter two perameter one is key or another is iterator
    // (in iterator if you can enter iterator which is not present in map then they given error Segmentation Fault )
    if(it != m.end()){
        m.erase(it);
    }
    print(m);
    // to clear the map use the .clear() function
    m.clear();
    print(m);
    return 0;

    return 0;
}