class Solution {
public:
    
    int ans=0;
    
    void count(TreeNode* root, vector<int> v)
    {
        if(!root) return; 
        if(v.size()==0) ans++;
        else if(v[v.size()-1]<=root->val) ans++;
        v.push_back(root->val);
        sort(v.begin(), v.end());
        count(root->left, v);
        count(root->right, v);
    }
    
    int goodNodes(TreeNode* root) {
        vector<int> v;
        count(root, v);
        return ans;
    }
};


//OR just keep count of maximum val
class Solution {
public:
    
    int goodNodes(TreeNode* root, int val=INT_MIN) {
        return root == nullptr ? 0 : (val <= root->val)  + goodNodes(root->left, max(root->val, val)) + goodNodes(root->right, max(root->val, val));
    }
};
