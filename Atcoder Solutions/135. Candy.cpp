// Problem link: https://leetcode.com/problems/candy/description/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int) ratings.size();
        if (n == 1) {
            return n;
        }
        vector<int> ans(n);
        auto is_valley = [&] (int i) {
            if ((i - 1 >= 0 and ratings[i - 1] > ratings[i]) and (i + 1 == n or ratings[i + 1] >= ratings[i])) {
                return true;
            }
            if ((i + 1 < n and ratings[i] < ratings[i + 1]) and (i - 1 == -1 or ratings[i - 1] >= ratings[i])) {
                return true;
            }
            return false;
        };
        for (int i = 0; i < n; ++i) {
            if (is_valley(i)) {
                int j = i;
                ans[j] = 1;
                while (j - 1 >= 0 and ratings[j - 1] > ratings[j]) {
                    --j;
                    ans[j] = max(ans[j], ans[j + 1] + 1);
                }
                j = i;
                while (j + 1 < n and ratings[j] < ratings[j + 1]) {
                    ++j;
                    ans[j] = max(ans[j], ans[j - 1] + 1);
                }
            }
        }
        return accumulate(ans.begin(), ans.end(), 0) + count(ans.begin(), ans.end(), 0);
    }
};
