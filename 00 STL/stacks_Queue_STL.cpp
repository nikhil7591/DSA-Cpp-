#include<bits/stdc++.h>
using namespace std;

// lect 1 stack and queue introduction
// lect 2 stack question balanced Brackets
bool isbalanced(string s){
    stack<char> str;
    for(int i =0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch=='{' || ch=='['){
            str.push(ch);
        }
        else{
            if(str.empty()){
                return false;
            }
            char top = str.top();
            if((ch==')' && top=='(') || (ch=='}' && top=='{')||(ch==']' && top=='[')){
                str.pop();
            }
            else{
                return false;
            }
        }
    }
    if(str.empty()){
        return true;
    }
    return false;
}
// lec3: stack question find Next greater element using stack
vector<int> nextGreaterElement(vector<int> v){
    int n = v.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i =0;i<n;i++){
        while(!s.empty() && v[s.top()]<v[i]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        ans[s.top()] = -1;
        s.pop();
    }
    return ans;
} 

int main(){
    // // lect1:
    // stack<int> s;
    // s.push(2);
    // // another stack operation pop , empty, top;

    // queue<int> q;
    // q.push(1);
    // // anotherr queue operation pop,front,empty;

    // Lect 2:
    // Solution:
    // string s;
    // cin>>s;
    // if(isbalanced(s)){
    //     cout<<s<<": ";
    //     cout<<"Yes, string is balanced"<<endl;
    // }else{
    //     cout<<s<<": ";
    //     cout<<"No, string is balanced"<<endl;
    // }
    // lect 3:
    // Solution:
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    vector<int> ans = nextGreaterElement(v);
    
    for(int i=0;i<n;i++){
        cout<<(ans[i] == -1? -1:v[ans[i]])<<" ";
    }
    cout<<endl;
    return 0;
}