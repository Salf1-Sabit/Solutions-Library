// Problem link: https://leetcode.com/problems/interleaving-string/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool sol (int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if (k == s3.size()) {
            return true;
        }
        int& ans = dp[i][j];
        if (ans != -1) {
            return ans;
        }
        ans = false;
        if (i < s1.size() and s1[i] == s3[k]) {
            ans |= sol(i + 1, j, k + 1, s1, s2, s3, dp);
        }
        if (j < s2.size() and s2[j] == s3[k]) {
            ans |= sol(i, j + 1, k + 1, s1, s2, s3, dp);
        }
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int l = s3.size();
        if (n + m != l) {
            return false;
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return sol(0, 0, 0, s1, s2, s3, dp);
    }
};
