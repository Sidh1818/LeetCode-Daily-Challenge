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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>children;

        for(const auto& d:descriptions){
            int parentV = d[0] , childV = d[1];
            bool isleft = d[2];

            if(mp.find(parentV) == mp.end())
                mp[parentV] = new TreeNode(parentV);

            if(mp.find(childV) == mp.end())
                mp[childV] = new TreeNode(childV);

            if(isleft)
                mp[parentV]->left = mp[childV];
            else
                mp[parentV]->right = mp[childV];

            children.insert(childV);
        }


        for(const auto& pair:mp){
            int val = pair.first;
            if(children.find(val) == children.end())
                return pair.second;
        }
        return nullptr;
    }
};