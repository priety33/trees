class Solution {
    int ans=0;
public:
    
    TreeNode* bstToGst(TreeNode* root) {
        
        if(!root) return NULL;
        
        bstToGst(root->right);
        ans+=root->val;
        root->val=ans;
        bstToGst(root->left);
        
        return root;
    }
};
