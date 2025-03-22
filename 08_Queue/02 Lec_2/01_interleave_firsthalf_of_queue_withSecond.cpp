#include<bits/stdc++.h>
#include<iostream>
using namespace std;

queue<int> solve(queue<int> q,int n){
    stack<int> s;
    int mid = n/2;
    for(int i =0 ;i<mid;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i =0;i<mid;i++){
        q.push(q.front());
        q.pop();
    }

    for(int i=0;i<n/2;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main(){
    queue<int> q;
    int n;
    cout<<"length of q ";
    cin>>n;

    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        q.push(num);
    }

    // Question is : Interleave first half of queue with second half
    queue<int> ans;
    ans = solve(q,n);
    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }

    return 0;
}