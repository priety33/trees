class Solution {
public:
    
    int depth(TreeNode* root, int x, int d, TreeNode* &p)
    {
        if(!root) return -1;
        if(root->val==x) return d;
        p=root;
        int h= depth(root->left, x, d+1, p);
        if(h==-1){
            p=root;
            h=depth(root->right, x, d+1, p);
        }
        return h;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* p1=root;
        TreeNode* p2=root;
        int d1= depth(root, x, 0, p1); 
        int d2= depth(root, y, 0, p2);
        if(p1!=p2 && d1==d2) return true;
        return false;
    }
};
