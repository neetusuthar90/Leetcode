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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,int preStart,
        int preEnd, int inStart, int inEnd, map<int, int> &mp){
        
        //Base Case
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int rIdx = mp[root->val];
        int nElem = rIdx - inStart;

        root->left = constructTree(preorder,inorder,preStart+1,preStart+nElem,
            inStart, rIdx-1, mp);
        root->right = constructTree(preorder,inorder,preStart+nElem+1,preEnd,rIdx+1,inEnd,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, preEnd = preorder.size()-1;
        int inStart = 0, inEnd = inorder.size()-1;

        map<int, int> mp;
        for(int i = inStart; i <= inEnd; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = constructTree(preorder,inorder,preStart,preEnd,inStart,inEnd,mp);
        return root;
    }
};