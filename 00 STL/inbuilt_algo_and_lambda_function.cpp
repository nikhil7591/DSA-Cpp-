#include<bits/stdc++.h>
using namespace std;

int main(){
    // cout<<[](int x){return x+2;}(2)<<endl;
    // return 0;

    vector<int> v = {-2,-3,-5};
    // all_of algorithm return true or false
    cout<< all_of(v.begin(),v.end(),[](int x){return x>0;});
    // any_of algo it is also return true or fasle
    cout<< any_of(v.begin(),v.end(),[](int x){return x>0;});
    // none_of algo it is return koi be match nhai karega to return true karega
    cout<< none_of(v.begin(),v.end(),[](int x){return x>0;});
}