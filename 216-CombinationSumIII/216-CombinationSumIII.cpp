class Solution {
public:
    void helper(int index, int k, int n, vector<int>& temp, vector<vector<int>>& res) {
        if (n == 0 && temp.size() == k) { // Base Case: Valid combination found
            res.push_back(temp);
            return;
        }
        if (index > 9 || temp.size() > k) return; // If we exceed valid numbers or size

        // Not Take: Skip current number
        helper(index + 1, k, n, temp, res);

        // Take: Include current number
        temp.push_back(index);
        helper(index + 1, k, n - index, temp, res);
        temp.pop_back(); // Backtrack
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(1, k, n, temp, res);
        return res;
    }
};
