Node* build(int post[], int si, int ei)
{
    if(si>ei) return NULL;
    Node* root= new Node(post[ei]);
    int i;
    for(i=si; i<=ei ; i++) if(post[i]>=root->data) break;
    root->left=build(post,si,i-1);
    root->right=build(post,i,ei-1);
    return root;
}

Node *constructTree (int post[], int size)
{
   if(size<=0) return NULL;
   int si=0, ei=size-1;
   return build(post,si,ei);
}
