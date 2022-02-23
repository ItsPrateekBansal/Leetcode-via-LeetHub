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
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int deepestLeavesSum(TreeNode* root) 
    {
        int h=height(root);
        queue<TreeNode *> q;
        q.push(root);
        int sum=0;
        int count=0;
        while(true)
        {
            int size=q.size();
            count++;
            if(count==h)
            {
                while(!q.empty())
                {
                    sum+=q.front()->val;
                    q.pop();   
                }
                return sum;
            }
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return 0;
    }
};
