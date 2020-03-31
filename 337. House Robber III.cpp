class Solution {
    int ans=0;
public:
    int rob(TreeNode* root)
    {
        if(!root) return 0;
        if(!root->right && !root->left) return root->val;
        
        int lsum=0, rsum=0, ll=0, lr=0, rr=0, rl=0;
        if(root->left)
        {
            lsum=rob(root->left);
            ll=rob(root->left->left);
            lr=rob(root->left->right);
        }
        if(root->right)
        {
            rsum=rob(root->right);
            rr=rob(root->right->right);
            rl=rob(root->right->left);
        }
        
        return max(root->val+ll+lr+rr+rl, lsum+rsum);
    }
};



//DP APPROACH
class Solution {
public:
    //lm, rm are immediate children
    int helper(TreeNode* root,int& lm,int& rm){ //children are passed by reference so that when we call on children, 
                                                 //we get the value of grandchildren also
        if(root==NULL) return 0;
        int ll=0,lr=0,rr=0,rl=0; //these are the grandchilren
        lm=helper(root->left,ll,lr); //its grandchildren-> children of it's immediate child
        rm=helper(root->right,rl,rr);
        cout << root->val << " " << lm <<" " << rm << " "<< ll << " " << lr << " " << rl << " " << rr << endl;
        return max(root->val+ll+lr+rr+rl,lm+rm);
    }
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        int lm=0,rm=0;
        int res=helper(root,lm,rm);
        return res;
    }
};
