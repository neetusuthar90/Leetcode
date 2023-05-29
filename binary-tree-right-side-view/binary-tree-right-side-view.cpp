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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
    
        q.push({root,1});
    
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* temp = p.first;
            int level = p.second;
        
            mp[level] = temp->val;
            
            if(temp->left){
                q.push({temp->left, level+1});
            }
            if(temp->right){
                q.push({temp->right, level+1});
            }
        }
        
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};