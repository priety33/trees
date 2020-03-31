class Solution {
    int ans=0;
public:
    
    int sum(TreeNode* root)
    {
        if(!root) return 0;
        int l=sum(root->left);
        int r=sum(root->right);
        ans+=abs(l-r);
        return root->val+l+r;
    }
    
    int findTilt(TreeNode* root) {
        
        if(!root) return 0;
        sum(root);
        return ans;
    }
};
