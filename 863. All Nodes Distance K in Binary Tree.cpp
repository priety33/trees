class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> v;
        if(!root) return v;
        TreeNode* p=root;
        map<TreeNode*,TreeNode*> parent;
        map<TreeNode*,bool> visited;
        fillparent(root,target,parent);
        TreeNode* t=target;
        visited[t]=true;
        find(t,K,v,parent,visited);
        return v;
    }
    
    void fillparent(TreeNode* root, TreeNode* target, map<TreeNode*,TreeNode*> &parent)
    {
        if(!root || root==target) return;
        if(root->left)
        {
            parent[root->left]=root;
            fillparent(root->left,target,parent);
        }
        if(root->right)
        {
            parent[root->right]=root;
            fillparent(root->right,target,parent);
        }
    }
    
    void find(TreeNode* t, int k, vector<int> &v,map<TreeNode*,TreeNode*> parent, map<TreeNode*,bool> &visited)
    {
        if(k==0)
        {
            v.push_back(t->val);
            return;
        }
        if(t->left && !visited[t->left])
        {
           visited[t->left]=true;
           find(t->left,k-1,v,parent,visited);
        }
        if(t->right && !visited[t->right]) 
        {
            visited[t->right]=true;
            find(t->right,k-1,v,parent,visited);
        }
        if(parent[t] && !visited[parent[t]])
        {
            visited[parent[t]]=true;
            find(parent[t],k-1,v,parent,visited);
        }
        return;
    }
    
};
