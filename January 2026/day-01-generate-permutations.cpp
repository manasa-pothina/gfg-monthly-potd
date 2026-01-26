/*
Problem: Generate permutations of an array
Platform: GeeksforGeeks POTD
Day: Day 1 (January Monthly Challenge)
Approach: Backtracking by swapping elements
Time Complexity: O(n! * n)
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int>& arr, vector<vector<int>>& ans) {
    if (index == arr.size()) {
        ans.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        solve(index + 1, arr, ans);
        swap(arr[index], arr[i]); // backtrack
    }
}

vector<vector<int>> permutations(vector<int>& arr) {
    vector<vector<int>> ans;
    solve(0, arr, ans);
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result = permutations(arr);

    for (auto& perm : result) {
        for (int x : perm)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
