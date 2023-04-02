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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)  return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        // flag is for LeftToRight
        bool flag = true;
        while(!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            for(int k=1; k<=n; k++){
                TreeNode* front = q.front();
                temp.push_back(front->val);
                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
                q.pop();
            }
            if(flag==false)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            flag = !flag;
        }
        
        return ans;
    }
};