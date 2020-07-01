class Solution {
public:
    int camera=0;
    
    int btc( TreeNode* root) {
        if(!root) return 0;
        int left= btc(root->left);
        int right= btc(root->right);
        
        if(left==0 && right==0) {
            //root is leaf-> place camera at my parent to minimise number of cameras
            return -1;
        }
        if(left==-1 || right==-1) {
            //either my left child or right child is leaf and need surveillance-> ill put camera on myself
            camera++; return 1;
        }
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        TreeNode* dummy= new TreeNode(-1); // add dummy node for cases where root is leaf.=> camera will be added there
        dummy->right= root;
        btc(dummy);
        return camera;
    }
};
