void storeinorder(Node* root, vector<int> &inorder)
{
    if(!root) return;
    storeinorder(root->left,inorder);
    inorder.push_back(root->data);
    storeinorder(root->right,inorder);
}

void replace(Node*root, vector<int> &inorder)
{
    if(!root) return;
    replace(root->left, inorder);
    root->data=*inorder.begin();
    inorder.erase(inorder.begin());
    replace(root->right, inorder);
}

Node *binaryTreeToBST (Node *root)
{
    vector<int> inorder;
    storeinorder(root, inorder);
    sort(inorder.begin(), inorder.end());
    replace(root, inorder);
    return root;
}
