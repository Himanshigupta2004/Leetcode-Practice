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
    void path(TreeNode* root,int targetSum,vector<int>& ans,vector<vector<int>>& finalans){
        if(root==NULL) return;
        ans.push_back(root->val);
        if(root->left==NULL && root->right==NULL && targetSum==root->val){
                finalans.push_back(ans);
        }
         path(root->left,targetSum-root->val,ans,finalans);
        path(root->right,targetSum-root->val,ans,finalans);
        ans.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> finalans;
        vector<int> ans;
       path(root,targetSum,ans,finalans);
       return finalans;
    }
};