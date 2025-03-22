#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Max HEAP 
class Heap{
    public:
        int arr[100];
        int size;

        Heap(){
            arr[0]=-1;
            size = 0;
        }

        void insert(int val){
            size = size+1;
            int index = size;
            arr[index] = val;

            while(index>1){
                int parent = index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index= parent;
                }
                else{
                    return;
                }
            }
        }

        // Deletion in heap
        void deleteNode(){
            if(size == 0){
                cout<<" Nothing to delete "<<endl;
            }
            // step1: put last element into the first index
            arr[1] =  arr[size];
            // step2: remove the last element
            size--;

            // step3:  take root node to its correct position;
            int i =  1;
            while(i<size){
                int leftside = 2*i;
                int rightside = 2*i+1;
                if(leftside<size && arr[i]<arr[leftside]){
                    swap(arr[i],arr[leftside]);
                    i = leftside;
                }
                else if(rightside<size && arr[i]<arr[rightside]){
                    swap(arr[i],arr[rightside]);
                    i = rightside;
                }
                else return;
            }
        }

        void print(){
            for(int  i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

// heapify algo tc O(logn)
// important algorithm 
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<n && arr[largest]<arr[left]){
        largest  = left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest  = right;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main(){
    
    Heap h;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.print();
    h.insert(55);
    h.insert(70);
    h.print();
    h.deleteNode();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n =5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing the array now "<<endl;
    for(int i =1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}