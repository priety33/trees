/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//simpler solution in solutions.
class Solution { 
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        TreeNode* current=root;
        while(current)
        {
            if(!current->left)
            {
                v.push_back(current->val);
                current=current->right; //traversing up from the threaded link
            }
            else
            {
                TreeNode* pre= current->left;
                while(pre->right && pre->right!=current)
                {
                    pre=pre->right;
                }
                
                if(!pre->right)
                {
                    pre->right=current; //creating a thread from inorder predecessor to current node => only after this node 
                                        //is printed (meaning whole left subtree is printed), will current get printed
                    current=current->left;
                }
                else
                {
                    pre->right=NULL; //removing threaded connections => whole left subtree of current is printed
                    v.push_back(current->val);// now current has to printed, after the left subtree
                    current=current->right;
                }
            }
        }
        return v;
    }
};
