class Solution {
public:
    
    TreeNode* build(vector<int>& inorder, int si, int ei, vector<int>& preorder, int sp, int ep)
    { 
        if(si>ei || sp>ep) return NULL;
        TreeNode* root= new TreeNode(preorder[sp]);
        int sizel=0, i;
        for(i=si; i<=ei ;i++) if(inorder[i]==root->val) break;
        sizel=i-si; //number of elements in left subtree
        root->left= build(inorder, si, i-1, preorder, sp+1, sp+sizel);
        root->right=build(inorder, i+1, ei, preorder, sp+sizel+1, ep);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= inorder.size();
        if(n==0) return NULL;
        int si=0, sp=0, ei=n-1, ep=n-1;
        return build(inorder, si, ei, preorder, sp, ep);
    }
};
