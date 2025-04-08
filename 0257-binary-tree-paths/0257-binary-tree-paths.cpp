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
        path+=to_string(root->val);
        if(root->left==NULL && root->right==NULL) {
            ans.push_back(path);
        }
        path+="->";
        paths(root->left,ans,path);
        paths(root->right,ans,path);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL) return ans;
        paths(root,ans,"");
        return ans;
    }
};