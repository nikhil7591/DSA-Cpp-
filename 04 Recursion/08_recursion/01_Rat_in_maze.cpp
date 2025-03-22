#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& arr) {
    if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && arr[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(vector<vector<int>>& arr, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
    // base case
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // 4 choices D,L,R,U

    // down
    int new_x = x + 1;
    int new_y = y;
    if (isSafe(new_x, new_y, n, visited, arr)) {
        path.push_back('D');
        solve(arr, n, ans, new_x, new_y, visited, path);
        path.pop_back();
    }

    // left
    new_x = x;
    new_y = y - 1;
    if (isSafe(new_x, new_y, n, visited, arr)) {
        path.push_back('L');
        solve(arr, n, ans, new_x, new_y, visited, path);
        path.pop_back();
    }

    // right
    new_x = x;
    new_y = y + 1;
    if (isSafe(new_x, new_y, n, visited, arr)) {
        path.push_back('R');
        solve(arr, n, ans, new_x, new_y, visited, path);
        path.pop_back();
    }

    // up
    new_x = x - 1;
    new_y = y;
    if (isSafe(new_x, new_y, n, visited, arr)) {
        path.push_back('U');
        solve(arr, n, ans, new_x, new_y, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<string> ans;
    int srcx = 0;
    int srcy = 0;

    if (arr[0][0] == 0) {
        return ans;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));

    string path = "";
    solve(arr, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<string> ans = searchMaze(arr,n);
    for(string i:ans){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}