#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(string str, int index, vector<string> &ans){
    // base case
    if(index>=str.length()){
        ans.push_back(str);
        return;
    }

    for(int i = index;i<str.length();i++){
        swap(str[index],str[i]);
        solve(str,index+1,ans);
        // backtracking
        swap(str[index],str[i]);
    }
}

vector<string> generatepermutation(string &str){
    vector<string> ans;
    int index = 0;
    solve(str,index,ans);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    
    string str = "abc";
    vector<string> ans = generatepermutation(str);

    for(int i =0 ;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}