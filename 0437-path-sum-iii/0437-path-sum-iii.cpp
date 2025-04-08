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
    int cnt=0;
    void solve(TreeNode* root,vector<long long>& ans,long long sum,int targetSum){
        if(!root) return;
        sum+=root->val;
        if(sum==targetSum) cnt++;
        for(auto it:ans){
            if(sum-it==targetSum) cnt++;
        }
        ans.push_back(sum);
        
        solve(root->left,ans,sum,targetSum);
        solve(root->right,ans,sum,targetSum);
        ans.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> ans;
        solve(root,ans,0,targetSum);
        return cnt;
    }
};