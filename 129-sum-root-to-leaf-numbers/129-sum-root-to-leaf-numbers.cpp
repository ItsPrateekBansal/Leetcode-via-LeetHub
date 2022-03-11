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
    void helper(TreeNode *root, int &ans, int curr) {
        if(!root) return;
        curr = (curr*10) + root->val;
        if(!root->left && !root->right) ans += curr;
        else {
            helper(root->left, ans, curr);
            helper(root->right, ans, curr);
        }
        // helper(root->left, ans, curr);
        // helper(root->right, ans, curr);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int curr = 0;
        helper(root, ans, curr);
        return ans;
    }
};