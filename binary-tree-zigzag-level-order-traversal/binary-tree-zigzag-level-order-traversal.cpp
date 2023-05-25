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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++){
                root = q.front();
                q.pop();
                if(root->left != NULL){
    	            q.push(root->left);
    	        }
    	        if(root->right != NULL){
    	            q.push(root->right);
    	        }
    	        temp.push_back(root->val);
            }
            if(level%2 == 0){
    	        reverse(temp.begin(), temp.end());
    	    }
            res.push_back(temp);
            level++;
        }
        return res;
    }
};