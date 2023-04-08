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
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> copies;
        Node *copy = new Node(node->val,{});
        copies[node] = copy;
        queue<Node*> qu;
        qu.push(node);

        while(!qu.empty()){
            Node *cur = qu.front();
            qu.pop();
            for(Node* nbd:cur->neighbors){
                if(copies.find(nbd)==copies.end()){
                    copies[nbd] = new Node(nbd->val,{});
                    qu.push(nbd);
                }
                copies[cur]->neighbors.push_back(copies[nbd]);
            }
        }
        return copy;
    }
};