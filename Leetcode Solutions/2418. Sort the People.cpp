/* One of the best solution - 11ms
   Problem link: https://leetcode.com/problems/sort-the-people/
   Time: O(nlogn)
   Space: O(n) */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = (int) names.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&] (int i, int j) {
            return heights[i] > heights[j];
        });
        vector<string> ans;
        for (auto i : ids) {
            ans.push_back(names[i]);
        }
        return ans;
    }
};
