/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* center(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;
        while(fast && fast->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        if(prev) prev->next=nullptr;
        return slow;     
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        ListNode* midnode=center(head);
        TreeNode* root=new TreeNode(midnode->val);
        if(head==midnode) return root;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(midnode->next);
        return root;
    }
};