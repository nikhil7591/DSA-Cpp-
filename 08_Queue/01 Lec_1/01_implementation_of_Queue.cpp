#include<iostream>
#include<queue>
using namespace std;

int main(){
    // create a Queue
    queue<int> q;
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);

    cout<< " Size of queue is "<<q.size()<<endl;
    q.pop();
    cout<< " Size of queue is "<<q.size()<<endl;
    cout<<" Front element is "<<q.front()<<endl;
    cout<<" back element is "<<q.back()<<endl;
    if(q.empty()){
        cout<<" q is empty "<<endl;
    }else{
        cout <<" q is not empty "<<endl;
    }

    q.emplace();
     cout<< " Size of queue is "<<q.size()<<endl;
    cout<<" Front element is "<<q.front()<<endl;
    cout<<" back element is "<<q.back()<<endl;

    return 0;
}