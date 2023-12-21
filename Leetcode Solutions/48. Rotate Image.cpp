// Problem link: https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int) matrix.size();
        for (int i = 0, m = n; i < n / 2; ++i, --m) {
            for (int j = i; j < m - 1; ++j) {
                int& a = matrix[i][j];
                int& b = matrix[j][n - 1 - i];
                int& c = matrix[n - 1 - i][n - 1 - j];
                int& d = matrix[n - 1 - j][i];
                int tmp = d;
                d = c;
                c = b;
                b = a;
                a = tmp;
            }
        }
    }
};
