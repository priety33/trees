class Solution {
public:
    
    int ans=0;
    
    void sum(TreeNode* root, bool p, bool gp)
    {
        if(!root) return;
        if(gp)
        {
            ans+=root->val;
            cout<<root->val<<" ";
        }
        
        if(p) gp=true;
        else gp=false;
        if(root->val%2==0) p=true;
        else p=false;
        sum(root->left, p, gp);
        sum(root->right, p, gp);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        sum(root, false, false);
        return ans;
    }
};
