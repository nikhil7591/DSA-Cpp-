#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int power(int a, int b){
    // Base Case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    //Recursion Call
    int ans = power(a,b/2);
    cout<<" recusion call "<<ans<<endl;
    if(b%2!=0){
        return a*(ans*ans);
    }
    else{
        return ans*ans;
    }
}

int main(){
    int a,b;
    cin>>a>>b;

    int ans = power(a,b);
    cout<<" Answer is "<<ans<<endl;
    return 0;
}