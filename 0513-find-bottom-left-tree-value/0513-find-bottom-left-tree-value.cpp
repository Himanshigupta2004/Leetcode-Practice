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
    int height(TreeNode* root){
        if(!root) return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        int hei=height(root);
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

        auto it=mp.find(hei);
        if(it != mp.end()){
            return it->second[0];
        }
        return 0;
    }
};