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
    void solve(TreeNode* root,int &ans,bool isleft){
        if(!root)
            return;
        if(!root->left && !root->right && isleft)
            ans+=root->val;
        solve(root->left,ans,true);
        solve(root->right,ans,false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        solve(root,ans,false);
        return ans;
    }
};