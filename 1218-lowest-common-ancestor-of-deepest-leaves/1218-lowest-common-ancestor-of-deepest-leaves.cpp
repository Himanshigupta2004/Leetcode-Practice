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

    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    TreeNode* lca(TreeNode* root,int depth,int maxdepth){
        if(root==NULL) return NULL;
        if(depth==maxdepth) return root;
        TreeNode* left=lca(root->left,depth+1,maxdepth);
        TreeNode* right=lca(root->right,depth+1,maxdepth);
        if(left && right) return root;
        return left?left:right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        // [6, 7, 4, 2, 5, 0, 8, 1, 3]

        int maxdepth=height(root);
        return lca(root,1,maxdepth);
    }
};