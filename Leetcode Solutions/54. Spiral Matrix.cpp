// Problem link: https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    bool is_valid (int next_row, int next_col, vector<vector<int>>& matrix) {
        int n = (int) matrix.size();
        int m = (int) matrix[0].size();
        if (next_row < n and next_col < m and next_row >= 0 and next_col >= 0 and matrix[next_row][next_col] != (int) 1e9) {
            return true;
        }
        return false;
    }
    void dfs (int i, int j, int k, vector<vector<int>>& dir, vector<vector<int>>& matrix, vector<int>& ans) {
        ans.push_back(matrix[i][j]);
        matrix[i][j] = (int) 1e9;
        if (!is_valid(i + dir[k][0], j + dir[k][1], matrix) 
            and !is_valid(i + dir[(k + 1) % 4][0], j + dir[(k + 1) % 4][1], matrix)) {
            return;       
        }
        if (!is_valid(i + dir[k][0], j + dir[k][1], matrix)) {
            k = (k + 1) % 4;
        }
        dfs(i + dir[k][0], j + dir[k][1], k, dir, matrix, ans);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        dfs(0, 0, 0, dir, matrix, ans);
        return ans;
    }
};
