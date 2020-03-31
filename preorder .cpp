// stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        TreeNode* current=root;
        while(!s.empty() || current)
        {
            if(current!=NULL)
            {
                ans.push_back(current->val);
                s.push(current);
                current=current->left;
            }
            else
            {
                current=s.top()->right;
                s.pop();
            }
        }
        return ans;
    }
};

//morris
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        TreeNode* current= root;
        while(current)
        {
            if(current->left)
            {
                TreeNode* pre=current->left;
                while(pre->right!=current && pre->right) pre=pre->right;
                
                if(pre->right==NULL)
                {
                    pre->right=current;
                    ans.push_back(current->val);
                    current=current->left;
                }
                else
                {
                    pre->right=NULL;
                    current=current->right;
                }
            }
            else
            {
                ans.push_back(current->val);
                current=current->right;
            }
        }
        return ans;
    }
};
