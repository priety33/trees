//iterative using stack takes less space than recursively building inorder array. Time of both same.
/*


    -hasNext is the easier of the lot since all we do in this is to return true if there are any elements left in the stack. 
    Otherwise, we return false. So clearly, this is an O(1) operation every time. 

    -next involves two major operations. 
    One is where we pop an element from the stack which becomes the next smallest element to return. 
    This is a O(1) operation. However, we then make a call to our helper function _inorder_left which iterates over
    a bunch of nodes. This is clearly a linear time operation i.e. O(N) in the worst case. This is true.

        However, the important thing to note here is that we only make such a call for nodes which have a right child. 
        Otherwise, we simply return. Also, even if we end up calling the helper function, it won't always process N nodes. 
        They will be much lesser. Only if we have a skewed tree would there be N nodes for the root. 
        But that is the only node for which we would call the helper function.

    Thus, the amortized (average) time complexity for this function would still be O(1).

Space complexity: The space complexity is O(h) which is occupied by our custom stack for simulating the inorder traversal. 
*/ 
class BSTIterator {
public:
    stack<TreeNode*> s;
    
    void leftinorder(TreeNode* root) {
        while(root) {
            s.push(root);
            root=root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        leftinorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* ans=s.top();
        s.pop();
        if(ans->right) {
            leftinorder(ans->right);
        }
        return ans->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};
