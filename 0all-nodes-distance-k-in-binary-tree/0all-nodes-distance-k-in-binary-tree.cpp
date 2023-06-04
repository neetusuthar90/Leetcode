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
    void parentNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = NULL;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                root = q.front();
                q.pop();
                if(root->left){
                    q.push(root->left);
                    parent[root->left] = root;
                }
                if(root->right){
                    q.push(root->right);
                    parent[root->right] = root;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parentNodes(root, parent);
        unordered_map<TreeNode*, bool> visited;

        
        queue<TreeNode*> q;
        q.push(tar);

        while(!q.empty() && k--){
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                }
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                }
                
                visited[temp] = true;
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};