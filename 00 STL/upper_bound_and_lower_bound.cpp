#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    
    // Sort the array
    sort(a.begin(), a.end());

    // Output the sorted array
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;

    // Using lower_bound in the sorted array
    // lower_bound returns an iterator pointing to the first element >= 3
    auto lower = lower_bound(a.begin(), a.end(), 6);
    
    if (lower != a.end()) {
        cout << "Lower bound for 3: " << *lower << endl;
    } else {
        cout << "Lower bound for 3 not found" << endl;
    }

    // Using upper_bound in the sorted array
    // upper_bound returns an iterator pointing to the first element > 3
    auto upper = upper_bound(a.begin(), a.end(), 3);

    if (upper != a.end()) {
        cout << "Upper bound for 3: " << *upper << endl;
    } else {
        cout << "Upper bound for 3 not found" << endl;
    }

    return 0;
}
