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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        int max_sum = INT_MIN;
        int res = 0;

        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
            if(sum > max_sum){
                max_sum = sum;
                res = level;
            }
        }

        return res;
    }
};