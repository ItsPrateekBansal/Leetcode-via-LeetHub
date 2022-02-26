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
    bool inRange(int low, int high, TreeNode *node) {
        if(node->val>=low && node->val <=high) return true;
        return false;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(inRange(low, high, root)) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        } else if(root->val > high) {
            return rangeSumBST(root->left, low, high);
        } else {
            return rangeSumBST(root->right, low, high);
        }
        return 0;
    }
};