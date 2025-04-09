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
    void calculate(TreeNode* root,vector<string>& binary,string bin){
        if(!root) return;
        bin+=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr) binary.push_back(bin);
        calculate(root->left,binary,bin);
        calculate(root->right,binary,bin);
    }

    int binarytodecimal(vector<string>& binary){
        for(string str:binary){
            int decimal=0;
            int power=0;
            for(int i=str.size()-1;i>=0;i--){
                if(str[i]=='1'){
                    decimal+=pow(2,power);
                }
                power++;
            }
            sum+=decimal;
        }
        return sum;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> binary;
        calculate(root,binary,"");
        binarytodecimal(binary);
        return sum;
    }
};