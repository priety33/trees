bool p(struct Node* root, int target)
{
    if(!root) return false;
    if(root->data==target) return true;
    if(p(root->left,target) || p(root->right,target))
    {
        cout<<root->data<<" ";
        return true;
    }
    return false;
}
bool printAncestors(struct Node *root, int target)
{
    p(root,target);
    cout<<endl;
    return true;
}
