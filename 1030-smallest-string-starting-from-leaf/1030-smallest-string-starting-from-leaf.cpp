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
 void paths(TreeNode* root,vector<string>& ans,string path){
        if(root==NULL) return;
        path+= char('a'+root->val);
        if(root->left==NULL && root->right==NULL) {
            ans.push_back(path);
            return;
        }
        paths(root->left,ans,path);
        paths(root->right,ans,path);
    }

    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        vector<string> result;
        paths(root,ans,"");
        for(auto str:ans){
            reverse(str.begin(),str.end());
            result.push_back(str);
        }
        sort(result.begin(),result.end());
        
        return result[0];
    }
};