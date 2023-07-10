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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0; 
        }
        else if(root->left == NULL && root->right == NULL){
            return 1;
        }
        
        int lans = minDepth(root->left);
        int rans = minDepth(root->right);
        if(lans == 0){
            return 1+rans;
        }
        else if(rans == 0){
            return 1+lans;
        }
        return 1+min(lans,rans);
    }
};