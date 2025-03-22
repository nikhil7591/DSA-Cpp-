#include<bits/stdc++.h>
using namespace std;

// map is data structure to store data in pair formate key and value,
// in map not use iterator in the foemate it+1 , you can use it++ only because 
// it+1 -> iterate on  +1 address 
// it++ ->iterate on linked next address  
// they have two tye map and unordered maps 
// In map can not create duplicate key they always create a unique key

// in Map to insert and access the data TC is O(log(n))
void print(map<int,string> &m){
    for(auto &pr : m){
        cout<< pr.first <<" "<<pr.second<<endl;
    }
    cout<<"Size of map "<<m.size()<<endl;
}

int main(){

    map<int,string> m;
    m[1] = "anss"; // tc O(log(n)) this tc is depend upon key datatype like id you enter key in string then 
    // TC is string.size()*log(n) hogi
    m[3] = "anss";
    m[5] = "anss";
    m[6]; // ager tum m[6] be likh doge na tabbi hamri tc O(log(n)) ho jaygi
    // one more option to store the data 
    m.insert({0,"dhd"});

    print(m);
    // to find any key in map
    auto it = m.find(3); // TC O(log(n))

    if(it == m.end()){
        cout<<"No value"<<endl;
    }else{
        cout<< it->first <<" " <<it->second<<endl;
    }

    // to erase or delete the key from map
    cout<<"After erase "<<endl;
    m.erase(5); // TC O(log(n))
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
}