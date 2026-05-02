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

    void inorder(TreeNode* node,vector<int>&inorderT){
        if(node->left)
            inorder(node->left,inorderT);
        inorderT.push_back(node->val);
        if(node->right)
            inorder(node->right,inorderT);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorderT;
        inorder(root,inorderT);
        int ans=inorderT[k-1];
        return ans;
    }
};