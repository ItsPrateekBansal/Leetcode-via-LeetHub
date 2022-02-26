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
    void helper(TreeNode *root, vector<string> &answer, string ans="") {
        if(!root) {
            // answer.push_back(ans);
            return;
        }
        ans += to_string(root->val);
        if(root->left) {
            helper(root->left, answer, ans+"->");
        } 
        if(root->right) {
            helper(root->right, answer, ans+"->");
        } 
        if(!root->right && !root->left) {
            answer.push_back(ans);
        }
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        helper(root, ret);
        return ret;
    }
};