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
int res=0;
    int countmax(TreeNode* root){
        if(!root) return 0;
        int left=countmax(root->left);
        int right=countmax(root->right);
        int leftpath=0,rightpath=0;
        if(root->left && root->val == root->left->val) {
           leftpath=left+1;
        }
        if(root->right && root->val==root->right->val){
            rightpath=right+1;
        }
       
        res=max(res,leftpath+rightpath);
        return max(leftpath,rightpath);


    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        countmax(root);
        return res;
    }
};