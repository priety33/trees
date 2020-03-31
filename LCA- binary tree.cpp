/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Time complexity of the below solution is O(n) as the method does a simple tree traversal in bottom up fashion.
class Solution {
public:
    
    TreeNode* lca(TreeNode* root, bool &vp, bool &vq, TreeNode* p, TreeNode* q)
    {
        if(!root) return NULL;
        
        if(root->val==p->val)
        {
            vp=true;
            return root; //=>value found
        }
        if(root->val==q->val)
        {
            vq=true;
            return root; //=>value found
        }
        
        TreeNode* leftlca= lca(root->left, vp, vq, p, q);
        TreeNode* rightlca= lca(root->right, vp, vq, p, q);
        
        if( leftlca && rightlca ) return root; //=>value found in both left and right->root is lca.
        
        if(leftlca) return leftlca; //=>value only in left subtree => this may be ancestor, if second value is present in tree
        else if(rightlca) return rightlca; //=>value only in right subtree => this may be ancestor, if second value is present in tree
        else return NULL;
    }
    
    bool find(TreeNode* root, TreeNode* a)
    {
        if(!root) return false;
        if(root->val==a->val || find(root->left,a) || find(root->right, a)) return true;
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool vp=false;
        bool vq=false;
        TreeNode* ans= lca(root, vp, vq, p, q);
        if(vp && vq || vp && find(ans,q) || vq && find(ans,p)) return ans; //=>fins(ans,p)- is p present in subtree rooted with our lca(ans)?
        return NULL; //=> one of p or q is not present in tree-> vp is false or vq is false
    }
};

//O(h)- storing parents



