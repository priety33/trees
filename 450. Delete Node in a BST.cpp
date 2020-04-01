class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(key>root->val) root->right=deleteNode(root->right, key); // root->right will change after deletion of the node,
                                                                   //therefore we need to attach returned value=> root->right=delete(root->right)
        else if(key<root->val) root->left=deleteNode(root->left, key);
        else
        {
            if(!root->left && !root->right) return NULL;
            else if(!root->left) return root->right;
            else if(!root->right) return root->left;
            else
            {
                TreeNode* smallest=root->right;  //finding smallest value in right subtree to replace current root
                while(smallest->left) smallest=smallest->left;
                
                //replace
                root->val=smallest->val;
                //delete this smallest value in right subtree
                root->right=deleteNode(root->right, smallest->val);
            }
        }
        return root;   
    }
};
