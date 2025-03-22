#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i= 0;i<n;i++){
        cin>>v[i];
    }
    // min element in arr
    int min = *min_element(v.begin(),v.end());
    cout<<min<<endl;
    // max element in arr
    int max = *max_element(v.begin(),v.end());
    cout<<max<<endl;

    // calculate the sum of arr
    int sum = accumulate(v.begin(),v.end(),0);
    cout<<sum<<endl;

    // count function given the count of element of arr
    int ct = count(v.begin(),v.end(),4);
    cout<<ct<<endl;

    // find function
    int ele = *find(v.begin(),v.end(),5);
    cout<<ele<<endl;

    // reverse
    reverse(v.begin(),v.end());
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    
    return 0;
}