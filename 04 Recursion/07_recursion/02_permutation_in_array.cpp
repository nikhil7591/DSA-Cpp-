#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>>& ans) {
    // Base case
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        // Backtracking
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permutations(vector<int>& vec) {
    vector<vector<int>> ans;
    int index = 0;
    solve(vec, index, ans);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> ans = permutations(nums);
    cout<<endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
