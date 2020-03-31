class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        TreeNode* current=root;
        while(current || !s.empty())
        {
            if(current)
            {
                s.push(current);
                ans.insert(ans.begin(),current->val); //either insert at front, or reverse at end
                current=current->right;
            }
            else
            {
                current=s.top()->left;
                s.pop();
            }
        }
        return ans;
    }
};
//for post, change left to right, and right to left in preorder -> now, reverse the preorder array.
