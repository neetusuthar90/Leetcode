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
    void getParents(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent){
        if(root == NULL){
            return;
        }

        parent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    parent[node->left] = node;
                }

                if(node->right){
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        getParents(root, parent);

        unordered_map<TreeNode*, bool> visited;

        queue<TreeNode*> todo;
        todo.push(target);

        while(!todo.empty() && k--){
            int size = todo.size();
            while(size--){
                TreeNode* temp = todo.front();
                todo.pop();

                if(parent[temp] && !visited[parent[temp]]){
                    todo.push(parent[temp]);
                }

                if(temp->left && !visited[temp->left]){
                    todo.push(temp->left);
                }

                if(temp->right && !visited[temp->right]){
                    todo.push(temp->right);
                }

                visited[temp] = true;
            }
        }

        vector<int> ans;

        while(!todo.empty()){
            ans.push_back(todo.front()->val);
            todo.pop();
        }
        return ans;
    }
};