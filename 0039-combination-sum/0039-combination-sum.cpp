class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, int target, vector<int>& candidates, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0)
            return;

        temp.push_back(candidates[i]);
        solve(i, target - candidates[i], candidates, temp);
        temp.pop_back();

        solve(i + 1, target, candidates, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0, target, candidates, temp);
        return ans;
    }
};
