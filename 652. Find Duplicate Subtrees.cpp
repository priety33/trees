class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> v;
        map<string,int> m; //string stores the inorder traversal of every node, considering it as root
        build(m,v,root);  // even if return type is not void, it is not necessary to store the result somewhere.
        return v;
    }
    
    string build(map<string,int> &m, vector<TreeNode*> &v, TreeNode* root) //calls for calculating inorder on every node on by one
    {
        if(!root) return "null";
        string a=to_string(root->val)+","+build(m,v,root->left)+","+build(m,v,root->right); // commas are used to handle the case of double digits, such as to separate 44 fom 4,4
        m[a]++;
        if(m[a]==2) v.push_back(root);
        return a;
    }
};
