/*
https://csactor.blogspot.com/2018/08/dsw-day-stout-warren-algorithm-dsw.html

Algorithm

    Convert the initial tree into a vine. By doing right rotations, we flatten a tree into a 'linked list', 
    where the head is the former leftmost node, and tail - former rightmost node.
    As you convert the tree into a vine, count the total number of nodes in cnt.
    Calculate the height of the closest perfectly balanced tree: h = log2(cnt + 1).
    Calculate the number of nodes in the closest perfectly balanced tree: m = pow(2, h) - 1.
    Left-rotate cnt - m nodes to cover up the excess of nodes.

    Note: you rotate the root node, then you rotate the right child of the new root node, and so on. 
    In other words, left rotations are performed on every second node of the vine. See pictures below for the illustration.

    Left-rotate m / 2 nodes.
    Divide m by two and repeat the step above while m / 2 is greater than zero.
 */

class Solution {
public:
    
    //create linked list from tree
    int buildvine(TreeNode* grand, int cnt=0) {
        TreeNode* n= grand->right;
        while(n) {
            if(n->left)
            {
                TreeNode* old_n= n;
                n=n->left;
                old_n->left= n->right;
                n->right= old_n;
                grand->right= n;
            }
            else
            {
                cnt++;
                grand=n;
                n=n->right;
            }
        }
        return cnt;
    }
    
    //left rotation across grands's right child => for every second node in tree
    void compress( TreeNode* grand, int m) {
        TreeNode* n= grand->right;
        while(m-- > 0) {
            TreeNode* old_n= n;
            n= n->right;
            grand->right= n;
            old_n->right= n->left;
            n->left= old_n;
            grand=n;
            n= n->right;
        }
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode grand;
        grand.right =root;
        int count= buildvine(&grand);
        
        //m= number of nodes that should be present in complete balanced tree
        int m= (int)pow(2,(int)log2(count+1))-1;
        //preprocessing- extra rotations for extra nodes
        compress(&grand, count-m);
        
        //remaining rotations
        for(m=m/2; m>0; m/=2) {
            compress(&grand, m);
        }
        return grand.right;
    }
};
