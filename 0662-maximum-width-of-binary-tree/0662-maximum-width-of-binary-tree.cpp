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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int maxwidth=0;
        while(!q.empty()){
            long long leftindex=q.front().second;
            long long rightindex=q.back().second;
            maxwidth=max(maxwidth,static_cast<int>(rightindex-leftindex+1));
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [node,index]=q.front();
                q.pop();
                long long newindex=index-leftindex;
                if(node->left){
                    q.push({node->left,2*newindex});
                }
                if(node->right){
                    q.push({node->right,2*newindex+1});
                }
            }
        }
        return maxwidth;
    }
};