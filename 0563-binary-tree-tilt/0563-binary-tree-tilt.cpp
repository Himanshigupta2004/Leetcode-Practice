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
int sum=0;
    int calculate(TreeNode* root){
        if(!root) return 0;
        if(root->left==nullptr && root->right==nullptr) return root->val;
        int left=calculate(root->left);
        int right=calculate(root->right);
        sum+=abs(left-right);
        return left+right+root->val;
    }

    int findTilt(TreeNode* root) {
        if(!root) return 0;
        calculate(root);
        return sum;

    }
};