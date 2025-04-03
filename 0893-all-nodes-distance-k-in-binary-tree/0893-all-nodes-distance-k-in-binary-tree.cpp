/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<int,TreeNode*> parentmap;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
            auto frontnode=q.front();
            q.pop();
            if(frontnode->left){
                parentmap[frontnode->left->val]=frontnode;
                q.push(frontnode->left);
            }
            if(frontnode->right){
                parentmap[frontnode->right->val]=frontnode;
                q.push(frontnode->right);
            }
            }
        }

        unordered_map<int,int> visited;
        q.push(target);
        while(k-- && !q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();
                visited[top->val]=1;
                if(top->left && !visited[top->left->val]){
                    q.push(top->left);
                }
                if(top->right && !visited[top->right->val]){
                    q.push(top->right);
                }
                if(parentmap[top->val] && !visited[parentmap[top->val]->val]){
                    q.push(parentmap[top->val]);
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    

    }
};