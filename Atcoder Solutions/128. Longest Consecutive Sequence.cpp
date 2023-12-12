// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> present;
        for (auto num : nums) {
            present[num] = true;
        }
        int ans = 0;
        unordered_map<int, bool> seen;
        for (auto [u, v] : present) {
            if (seen.find(u) != seen.end()) {
                continue;
            }
            seen[u] = true;
            int cur_node = u;
            int chain_len = 1;
            while (present.find(cur_node + 1) != present.end()) {
                cur_node = cur_node + 1;
                seen[cur_node] = true;
                chain_len += 1;
            }
            cur_node = u;
            while (present.find(cur_node - 1) != present.end()) {
                cur_node = cur_node - 1;
                seen[cur_node] = true;
                chain_len += 1;
            }
            ans = max(ans, chain_len);
        }
        return ans;
    }
};
