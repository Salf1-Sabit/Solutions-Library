// Problem link: https://leetcode.com/problems/word-search/?envType=study-plan-v2&envId=top-interview-150
// Unique Solution: Simple and clean code | backtracking approach

class Solution {
public:
    int n, m;
    bool sol (int row, int col, int word_id, const string& word, const vector<vector<char>>& board, vector<vector<bool>>& seen_cell) {
        if (word_id == (int) word.size()) {
            return true;
        }
        if (row >= n or row < 0 or col >= m or col < 0 or seen_cell[row][col]) {
            return false;
        }
        bool good = false;    
        seen_cell[row][col] = true;
        if (board[row][col] == word[word_id]) {
            good |= sol(row + 1, col, word_id + 1, word, board, seen_cell);
            good |= sol(row - 1, col, word_id + 1, word, board, seen_cell);
            good |= sol(row, col + 1, word_id + 1, word, board, seen_cell);
            good |= sol(row, col - 1, word_id + 1, word, board, seen_cell);
        }
        seen_cell[row][col] = false;
        return good;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool possible = false;
        n = (int) board.size();
        m = (int) board[0].size();
        vector<vector<bool>> seen_cell(n, vector<bool>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                possible |= sol(i, j, 0, word, board, seen_cell);
            }
        }
        return possible;
    }
};
