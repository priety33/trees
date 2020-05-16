class Solution {
public:
    
    string tree2str(TreeNode* t)
    {
        if(!t) return "";
        string l= tree2str(t->left);
        string r= tree2str(t->right);
        string a=to_string(t->val);
        if(l=="" && r=="") return a;
        else if(r=="") return a+= "(" + l + ")";
        return a+= "(" + l + ")" + "(" + r + ")";
    }
};
