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
    int ht(TreeNode* root){
        if(root==NULL)
            return -1;
        return 1+max(ht(root->right),ht(root->left));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;

        return abs(ht(root->right) - ht(root->left))<2 && isBalanced(root->right) && isBalanced(root->left);
    }
};