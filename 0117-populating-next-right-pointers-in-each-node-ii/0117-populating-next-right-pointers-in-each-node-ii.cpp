/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node* head=root;
        while(head){
            Node* curr=head;
            Node* nextptr=nullptr;
            Node* prevptr=nullptr;
            while(curr){
                if(curr->left){
                    if(prevptr) prevptr->next=curr->left;
                    else nextptr=curr->left;
                    prevptr=curr->left;
                }
                if(curr->right){
                    if(prevptr) prevptr->next=curr->right;
                    else nextptr=curr->right;
                    prevptr=curr->right;
                }

                curr=curr->next;

            }
            head=nextptr;
        }
        return root;

    }
};