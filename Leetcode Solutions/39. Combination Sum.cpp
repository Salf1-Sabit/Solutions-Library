// Problem link: https://leetcode.com/problems/combination-sum/?envType=study-plan-v2&envId=top-interview-150
// Unique solution: Unbounded knapsack approach

class Solution {
public:
    vector<vector<int>> all_combinations;
    void sol (int cur_id, int cur_sum, int target, vector<int>& seq, const vector<int>& candidates) {
        if (target == cur_sum) {
            all_combinations.push_back(seq);
            return;
        }
        if (cur_sum > target or cur_id == (int) candidates.size()) {
            return;
        }
        sol(cur_id + 1, cur_sum, target, seq, candidates);   
        seq.push_back(candidates[cur_id]);
        sol(cur_id, cur_sum + candidates[cur_id], target, seq, candidates);   
        seq.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> seq;
       sol(0, 0, target, seq, candidates); 
       return all_combinations;
    }
};
