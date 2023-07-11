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
    int rob(TreeNode* root) {
        if(root == NULL) return 0;

        pair<int,int> res;
        res = helper(root);

        return max(res.first, res.second);
    }

    pair<int,int> helper(TreeNode* root){
        if(root == NULL){
            pair<int,int> res = {0,0};
            return res;
        }

        pair<int,int> res;
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);

        res.first = root->val + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);

        return res;
    }
};