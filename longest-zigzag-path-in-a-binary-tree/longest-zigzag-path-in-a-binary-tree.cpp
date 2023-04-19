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
    int maxlen = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root,true,0);
        dfs(root,false,0);
        return maxlen;
    }

    void dfs(TreeNode* root, int fromleft, int ziglen){
        if(root == NULL) return;

        maxlen = max(maxlen,ziglen);
        if(fromleft){
            dfs(root->left,false,ziglen+1);
            dfs(root->right,true,1);
        }
        else{
            dfs(root->right,true,ziglen+1);
            dfs(root->left,false,1);
        }
        return;
    }
};