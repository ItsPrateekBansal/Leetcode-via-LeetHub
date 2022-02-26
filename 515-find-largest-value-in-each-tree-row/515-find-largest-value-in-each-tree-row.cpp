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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> answer;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()) {
            int n = q.size();
            int maxi = INT_MIN;
            for(int i = 0 ; i < n ; i++) {
                TreeNode *top = q.front();
                q.pop();
                maxi = max(maxi, top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            answer.push_back(maxi);
        }
        return answer;
    }
};