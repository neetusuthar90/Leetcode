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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> todo;

        todo.push({root,{0,0}});

        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();

            TreeNode* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(temp->val);

            if(temp->left){
                todo.push({temp->left, {x-1,y+1}});
            }
            if(temp->right){
                todo.push({temp->right, {x+1,y+1}});
            }
        }

        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                for(auto i:q.second){
                    col.push_back(i);
                }
            }
            res.push_back(col);
        }

        return res;
    }
};