void multiply(node* root1, node* root2, int &ans)  //initially ans=root->data*root->data
{
    if(!root1 || !root2) return;
    
    ans+=root1->data+root->data;
    multiply(root1->left,root2->right);
    multiply(root1->right,root2->left);
}
