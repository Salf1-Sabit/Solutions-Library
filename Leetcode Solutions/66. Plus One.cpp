class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1, sum = 0;
        int n = (int) digits.size();
        for (int i = n - 1; i >= 0; --i) {
            sum = digits[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) {
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
