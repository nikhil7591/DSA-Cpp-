#include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;

// Implementation of Stack

class Stack{
    // properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size){
        this-> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if( size - top >1){ // here check atleast one space is present
            top++;
            arr[top] = element;
        }
        else{
            cout<< " Stack Overflow "<<endl;
        }
    }
    void pop(){
        if(top >= 0){ // here check atleast one element present in Stack
            top--;
        }
        else{
            cout<<" Stack UnderTaking "<<endl;
        }
    }

    int peek(){
        if( top >=0 && top<size){
            return arr[top];
        }
        else{
            cout<< " Stack is Empty "<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};


int main(){

   // In Interviwer ask make the Implimentation of stack

    Stack st(5);
    st.push(22);
    st.push(23);
    st.push(24);
    st.push(25);
    st.push(26);

    // return top element
    cout<< " Top element is "<< st.peek()<<endl;

    // pop 
    st.pop();
    cout<< " Top element is "<< st.peek()<<endl;

    // check stack is empty
    if(st.isEmpty()){
        cout<<" Stack is Empty "<<endl;
    }else{
        cout<<" stack is not Empty "<<endl; 
    }


    /*
    stack<int> s;
    //  Add element in stack
    s.push(2);
    s.push(3);
    s.push(12);

    // remove element 
    s.pop(); // they remove the last elemrnt in stack which is 12
    // now see which element in top
    cout<<" Printing the top element in stack: "<<s.top()<<endl;
    // now check stack is empty or not
    if(s.empty()){
        cout<<" Satck is empty "<<endl;}
    else{
        cout<<" Stack is not empty "<<endl;
    }
    // now check size of stack 
    cout<<" Size of stack is "<<s.size()<<endl;
    */
    return 0;
}