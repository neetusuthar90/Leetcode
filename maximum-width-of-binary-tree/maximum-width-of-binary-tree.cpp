
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        
        // I am using intialising list
        q.push({root, 0});      // also can use make_pair
        
        while(!q.empty())
        {
            int cnt = q.size();
            int curmin = q.front().second; //Min in current level
            int start, end;
            for(int i = 0; i <cnt; ++i)
            {
                int idx = q.front().second - curmin;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i == 0){
                    start = idx;
                }
                if(i == cnt-1){
                    end = idx;
                }
                // if  left child exist
                if(temp->left != NULL)
                    q.push({temp->left, (long long)2 * idx + 1});
                
                // if right child exist
                if(temp->right != NULL)
                    q.push({temp->right, (long long) 2 * idx + 2});
            }
            res = max(res,end-start+1);
        }
        
        return res;
        
    }
};