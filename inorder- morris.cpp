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
                current=current->right;
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
                    pre->right=current;
                    current=current->left;
                }
                else
                {
                    pre->right=NULL; //removing threaded connections
                    v.push_back(current->val);
                    current=current->right;
                }
            }
        }
        return v;
    }
};
