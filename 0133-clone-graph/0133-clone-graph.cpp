/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* clone=new Node(node->val,{});
        mp[node]=clone;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            for(Node* it:curr->neighbors){
                if(mp.find(it)==mp.end()){
                    mp[it]=new Node(it->val,{});
                    q.push(it);
                }
                mp[curr]->neighbors.push_back(mp[it]);
            } 
        }
        return clone;
    }
};