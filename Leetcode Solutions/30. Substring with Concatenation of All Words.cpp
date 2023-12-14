// Problem link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_len = (int) s.size();
        int words_len = (int) words.size();
        int word_len = (int) words[0].size();
        unordered_map<string, int> words_occ;
        for (auto word : words) {
            words_occ[word]++;
        }
        vector<int> indexes;
        for (int i = 0; i < word_len; ++i) {
            int l = i, r = i;
            unordered_map<string, int> s_occ;
            while (r < s_len) {
                if (r - l == word_len * words_len) {
                    indexes.push_back(l);
                    --s_occ[s.substr(l, word_len)];
                    l += word_len;
                }
                if (r + word_len - 1 >= s_len) {
                    break;
                }
                string next_word = s.substr(r, word_len);
                ++s_occ[next_word];
                r += word_len;
                if (words_occ.find(next_word) == words_occ.end()) {
                    while (l < r) {
                        --s_occ[s.substr(l, word_len)];
                        l += word_len;
                    }
                    continue;
                }   
                while (s_occ[next_word] > words_occ[next_word]) {
                    --s_occ[s.substr(l, word_len)];
                    l += word_len;
                }
            }
            if (r - l == word_len * words_len) {
                indexes.push_back(l);
            }
        }
        return indexes;
    }
};
