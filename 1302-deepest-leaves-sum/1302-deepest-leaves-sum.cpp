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
    int deepest, answer;
public:
    void helper(TreeNode *root, int depth) {
        if(!root) return ;
        if(!root->left && !root->right && depth==deepest) {
            answer += root->val;
        } 
        if(!root->left && !root->right && depth > deepest) {
            answer = root->val;
            deepest = depth;
        }
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        deepest = 0;
        answer = 0;
        helper(root, 0);
        return answer;
    }
};