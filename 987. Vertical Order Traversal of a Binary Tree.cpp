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
    void print(TreeNode* root, int x, int y, map<int,vector<pair<int,int>>> &h )
    {
        if(!root) return;
        h[x].push_back(make_pair(y,root->val));
        if(root->left) print(root->left,x-1,y+1,h);
        if(root->right) print(root->right,x+1,y+1,h);
        return;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) return v;
        map<int,vector<pair<int,int>>> h; 
        print(root,0,0,h);
        for(auto it=h.begin(); it!=h.end();it++)
        {
            vector<pair<int,int>> y=(*it).second;
            sort(y.begin(),y.end());
            vector<int> t;
            int n=y.size();
            for(int i=0;i<n;i++) t.push_back(y[i].second);
            v.push_back(t);
        }
        return v;
    }
};
