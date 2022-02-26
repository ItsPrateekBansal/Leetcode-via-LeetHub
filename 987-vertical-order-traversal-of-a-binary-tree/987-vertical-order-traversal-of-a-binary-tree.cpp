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
    void helper(TreeNode* root, vector<pair<pair<int, int> , int>> &cors, int x, int y) {
        if(!root) return ;
        cors.push_back({{x,y}, root->val});
        helper(root->left, cors, x-1, y+1);
        helper(root->right, cors, x+1, y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<pair<int, int>, int>> cors;
        helper(root, cors, 0, 0);
        sort(cors.begin(), cors.end());
        vector<vector<int>> answer;
        for(int i = 0 ; i < cors.size() ; i++) {
            // cout << cors[i].second->val << " " << cors[i].first.first << " " << cors[i].first.second << endl;
            int bar = cors[i].first.first;
            vector<int> ans;
            while(i<cors.size() && cors[i].first.first == bar) {
                ans.push_back(cors[i].second);
                i++;
            }
            i--;
            answer.push_back(ans);
        }
        return answer;
    }
};