/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* a=root->left;
        TreeNode* temp=root->right;
        if(a)
        {
            root->left=NULL;
            flatten(a);
            root->right=a;
            while(a->right) a=a->right;
            a->right=temp;
        }
        flatten(temp);
        return;
    }
};
