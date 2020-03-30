class Solution {
    int ans=0;
public:
    int rob(TreeNode* root)
    {
        if(!root) return 0;
        if(!root->right && !root->left) return root->val;
        
        int lsum=0, rsum=0, ll=0, lr=0, rr=0, rl=0;
        if(root->left)
        {
            lsum=rob(root->left);
            ll=rob(root->left->left);
            lr=rob(root->left->right);
        }
        if(root->right)
        {
            rsum=rob(root->right);
            rr=rob(root->right->right);
            rl=rob(root->right->left);
        }
        
        return max(root->val+ll+lr+rr+rl, lsum+rsum);
    }
};
