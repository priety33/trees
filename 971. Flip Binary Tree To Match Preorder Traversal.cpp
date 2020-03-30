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
    
    int index=0;
    vector<int> v;
    
public:
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        
        if(!root) return v;
        build(root,voyage);
        return v;
    }
    
    void build(TreeNode* root, vector<int>& voyage)
    {
        if(!root) return ;
        
        if(voyage[index]==root->val)
        {
            index++;
            if(root->left && voyage[index]==root->left->val)
            {
                build(root->left,voyage);
                build(root->right,voyage);
            }
            else if(root->right && voyage[index]==root->right->val)
            {
                if(root->left) v.push_back(root->val); //if root->left==NULL, then our preorder is correct and no need to flip
                build(root->right,voyage);
                build(root->left,voyage);
            }
            else if(root->left || root->right) //atleast one of child!=NULL, but still they were not able to match preorder
            {
                v.clear();
                v.push_back(-1);
                return ;
            }
        }
        else
        {
            v.clear();
            v.push_back(-1);
            return ;
        }
        return;
    }
};
