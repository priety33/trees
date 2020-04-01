class Solution {
public:
    
    TreeNode* build(vector<int>& inorder, int si, int ei, vector<int>& postorder, int sp, int ep)
    { 
        if(si>ei || sp>ep) return NULL;
        TreeNode* root= new TreeNode(postorder[ep]);
        int sizel=0, i;
        for(i=si; i<=ei ;i++) if(inorder[i]==root->val) break;
        sizel=i-si; //number of elements in left subtree
        root->left= build(inorder, si, i-1, postorder, sp, sp+sizel-1);
        root->right=build(inorder, i+1, ei, postorder, sp+sizel, ep-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= inorder.size();
        if(n==0) return NULL;
        int si=0, sp=0, ei=n-1, ep=n-1;
        return build(inorder, si, ei, postorder, sp, ep);
    }
};
