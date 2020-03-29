int height(Node* root)
{
    if(!root) return 0;
    return 1+max(height(root->left),height(root->right));
}

int diameter(Node* node)
{
    if(!node) return 0;
   return max(1+height(node->left)+height(node->right),max(diameter(node->left),diameter(node->right)));
}
