/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    vector<int> p;
    
    bool checkpalin() {
        int odd=0;
        for(int i=0; i<10; i++) {
            if(p[i]&1) odd++;
            if(odd>1) break;
        }
        cout<<odd<<" ";
        return odd<=1;
    }
    
    void helper(TreeNode* root) {
        if(!root) return;
        p[root->val]++;
        if(!root->left && !root->right) {
            if( checkpalin() ) count++;
        }
        helper(root->left);
        helper(root->right);
        p[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        p.assign(10, 0);
        helper(root);
        return count;
    }
};
