void find(Node* root, vector<int> &v)
{
    if(!root) return;
    if(root->left && !root->right) v.push_back(root->left->data);
    else if(!root->left && root->right) v.push_back(root->right->data);
        find(root->left,v);
        find(root->right,v);
    return;
}

void printSibling(Node* node)
{
   // Your code here
   if(!node) return;
   vector<int> v;
   find(node,v);
   sort(v.begin(),v.end());
   if(v.size()==0) cout<<"-1";
   else for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
   return;
}
