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
        vector<int> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        map<int,vector<int>> mp;
        q.push({root,1});
        while(!q.empty()){
            auto [node,level]=q.front();
            q.pop();
            mp[level].push_back(node->val);
            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
        }

        for(auto it:mp){
            vector<int> i=it.second;
            sort(i.begin(),i.end());
            ans.push_back(i[i.size()-1]);
        }
        return ans;

    }
};