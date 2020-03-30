class Solution {
public:
    
    int sum (int &ans, TreeNode* root)
    {
        if (!root) return 0;
        if(!root->left && !root->right)
        {
            ans+=abs(root->val-1); // -1 because it will keep one for itself
            return root->val-1;
        }
        root->val=sum(ans,root->left)+sum(ans,root->right)+root->val;
        ans+=abs(root->val-1);
        return root->val-1;
    }
    
    int distributeCoins(TreeNode* root) {
        int ans=0;
        sum(ans,root);
        return ans;
    }
};
