class Solution {
public:
    int ans=INT_MIN;
    
    int maxsum(TreeNode* root) {
        if(!root) return 0;
        int lsum= max(0, maxsum(root->left));
        int rsum= max(0, maxsum(root->right));
        ans= max(ans, lsum+rsum+root->val);
        return max(lsum,rsum)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        maxsum(root);
        return ans;
    }
};
