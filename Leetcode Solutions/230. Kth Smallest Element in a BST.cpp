// Problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-interview-150
// Optimized solution: 4ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    stack<int> stk;
    void getKthSmallest (TreeNode* cur, int k) {
        if (cur == NULL or (int) stk.size() == k) {
            return;
        }
        getKthSmallest(cur -> left, k);
        if ((int) stk.size() == k) {
            return;
        }
        stk.push(cur -> val);
        getKthSmallest(cur -> right, k);
        if ((int) stk.size() == k) {
            return;
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        getKthSmallest(root, k);
        return stk.top();
    }
};
