class Solution {
public:
    
    bool same(TreeNode* a, TreeNode* b) {
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(same(a->left, b->right) && same(a->right, b->left) && a->val==b->val) return true;
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return same(root, root);
    }
};
