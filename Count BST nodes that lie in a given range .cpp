int getCountOfNode(Node *root, int l, int h)
{
  if(!root) return 0;
  if(root->data<=h && root->data>=l) return 1+getCountOfNode(root->left,l,h)+getCountOfNode(root->right,l,h);
  if(root->data>h) return getCountOfNode(root->left,l,h); //=> adding these two ifs below will decrease complexity
  if(root->data<l) return getCountOfNode(root->right,l,h);
}
