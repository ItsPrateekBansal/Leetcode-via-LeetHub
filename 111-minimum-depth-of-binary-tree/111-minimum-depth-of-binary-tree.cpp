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

    void helper(TreeNode *root, int &depth, int curr) {
        if(!root) return;
        if(!root->left && !root->right) {
            if(depth > curr) depth = curr;
            return ;
        }
        if(curr >= depth) return;
        if(root->left)
        helper(root->left, depth, curr+1);
        if(root->right)
        helper(root->right, depth, curr+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = INT_MAX;
        helper(root, depth, 0);
        return depth+1;
    }
};