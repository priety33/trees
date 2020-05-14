class Solution {
public:
    
    unordered_map<int,int> m;
    
    int sum(TreeNode* root)
    {
        if(!root) return 0;
        int l=sum(root->left);
        int r=sum(root->right);
        
        int s=l+r+root->val;
        m[s]++;
        return s;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sum(root);
        vector<int> ans;
        if(!root) return ans;
        int freq=0;
        for(auto i: m) 
        {
            if(i.second>freq)
            {
                ans.clear();
                ans.push_back(i.first);
                freq=i.second;
            }
            else if(i.second==freq) ans.push_back(i.first);
        }
        return ans;
    }
};
