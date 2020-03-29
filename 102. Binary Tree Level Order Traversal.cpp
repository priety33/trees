class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        
        queue<TreeNode*>q;
        TreeNode*curr=root;
        q.push(curr);
        
        while(!q.empty()){
            int s=q.size();
            vector<int>row;
            while(s!=0){
                TreeNode*temp=q.front();
                row.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            
                q.pop();
                s--;
            }
            res.push_back(row);
        }
        return res;
        
    }
};
