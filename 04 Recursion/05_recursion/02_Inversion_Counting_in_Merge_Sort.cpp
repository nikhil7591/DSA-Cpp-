#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Merge function to count inversions and merge two sorted halves
int merge(vector<int> &arr, int s, int e) {
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values to temporary arrays
    int k = s; // k is main array index
    for(int i = 0; i < len1; i++) {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for(int i = 0; i < len2; i++) {
        second[i] = arr[k++];
    }

    // Merge the two halves and count inversions
    int index1 = 0;
    int index2 = 0;
    k = s;
    int inv_count = 0; // Count of inversions

    while(index1 < len1 && index2 < len2) {
        if(first[index1] <= second[index2]) {
            arr[k++] = first[index1++];
        } else {
            arr[k++] = second[index2++];
            // All remaining elements in first array are greater than second[index2]
            inv_count += (len1 - index1);
        }
    }
    while(index1 < len1) {
        arr[k++] = first[index1++];
    }
    while(index2 < len2) {
        arr[k++] = second[index2++];
    }

    delete[] first;
    delete[] second;

    return inv_count;
}

// Recursive function to sort the array and return inversion count
int mergeSorted(vector<int> &arr, int s, int e) {
    if(s >= e) {
        return 0;
    }

    int mid = s + (e - s) / 2;

    // Count inversions in the left part
    int inv_count = mergeSorted(arr, s, mid);
    // Count inversions in the right part
    inv_count += mergeSorted(arr, mid + 1, e);
    // Count split inversions
    inv_count += merge(arr, s, e);

    return inv_count;
}

// Main mergeSort function to be called from main
int mergeSort(vector<int> &arr) {
    return mergeSorted(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 5, 3, 2, 4};
    int n = arr.size();

    int inv_count = mergeSort(arr);

    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Number of inversions: " << inv_count << endl;

    return 0;
}
