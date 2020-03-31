// Method that prints the bottom view.
void print(Node* root, int x, int y, map<int,pair<int,int>> &m)
{
    if(!root) return;
    if(m.find(x)==m.end()) m[x]=make_pair(y,root->data);
    else
    {
        if(y>=m[x].first) m[x]=make_pair(y,root->data); //print last of each y cordinate=>bottom view
    }
    if(root->left) print(root->left,x-1,y+1,m);
    if(root->right) print(root->right,x+1,y+1,m);
    return;
}

void bottomView(struct Node *root)
{
    //Your code here
    map<int,pair<int,int>> m;
    print(root,0,0,m);
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->second.second<<" ";
    }
    return;
}
