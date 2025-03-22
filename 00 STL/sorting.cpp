#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a ={1,4,2,3,5};
    sort(a.begin(),a.end());
    for(int i: a){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}